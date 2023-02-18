#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <locale.h>
#include <time.h>
#include <stdint.h>

double Set_Value, kp, kd, ki, Absolute_PID, Error_Value, Current_Value, Bias;
int chk=1;

float f_PID(double Current_Value, double Set_Value, double kp, double kd, double ki);


int menu()
{
	while(chk==1)
	{
		system("cls");
		printf("\n\tStart deðerini float cinsinden girin: ");
		scanf("%lf", &Current_Value);
		
		system("cls");
		printf("\n\tSet deðerini float cinsinden girin: ");
		scanf("%lf", &Set_Value);
		
		system("cls");
		printf("\n\tKp katsayýsýný float cinsinden girin: ");
		scanf("%lf", &kp);
		
		system("cls");
		printf("\n\tKd katsayýsýný float cinsinden girin: ");
		scanf("%lf", &kd);
		
		system("cls");
		printf("\n\tKi katsayýsýný float cinsinden girin: ");
		scanf("%lf", &ki);
		
		
		f_PID(Current_Value, Set_Value, kp, kd, ki);
	}
}

float f_PID(double Current_Value, double Set_Value, double kp, double kd, double ki)
{
	system("cls");
	
	
	int64_t t_count = 0;
	double Previous_Error, Delta_Error, Variable_P, Integral_Value, Variable_D, Variable_I, D_Time = 0;
	
	time_t start,end;
	time (&start);
	
	
	
	while(Current_Value<Set_Value-0.000005 || Current_Value>Set_Value+0.000005)
	{
		Error_Value=Set_Value-Current_Value;
		
		Variable_P=kp*Error_Value;
		Integral_Value+=Error_Value;
		Variable_D=kd*Delta_Error;
		
		Delta_Error=Error_Value-Previous_Error;
		Variable_I=ki*Integral_Value;
		Absolute_PID=(Variable_P)+(Variable_D)+(Variable_I);
		
		
		printf("\n  Err: %lf / dErr: %lf / P: %lf / I: %lf / D: %lf / AbsPID: %lf / Value: %lf <----> SetValue: %lf / Kp: %lf / Ki: %lf / Kd: %lf \n", Error_Value, Delta_Error, Variable_P, Variable_I, Variable_D, Absolute_PID, Current_Value, Set_Value, kp, ki, kd);
		
		
		t_count++;
		Current_Value=Current_Value+Absolute_PID;
		
		
		if(Absolute_PID==0||Delta_Error==0) break;
		
		
		Previous_Error=Error_Value;
	}
	
	time(&end);
	D_Time=difftime (end,start);
	

	printf("\n\tÖðrenme Tamamlandý\n\tBu sistem hedeflenen deðer için %lf saniyede %lld kez geri beslendi.\n\n\tYeni eðitim baþlatmak için 1'e basýn\n\tistemiyorsanýz 0'a basýn ", D_Time,t_count);
	scanf("%d", &chk);
	return chk;
}



int main()
{
	setlocale(LC_ALL, "Turkish");
	menu();
}
