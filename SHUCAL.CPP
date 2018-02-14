//CALENDER APP

//include all nesscary header_files
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

//making class for date
class date
{
 public:
 int dd;
 int mm;
 int yyyy;
 int chk_lpyr;

   void getdate()   //getting date from the user
   {
   cout<<"Enter day : ";
   cin>>dd;
   cout<<"Enter month : ";
   cin>>mm;
   cout<<"Enter year : ";
   cin>>yyyy;
   chk_lpyr=yyyy;
   }
   void putdate()  //put the date
   {
   cout<<"\nYou entered date is :- "<<dd<<"-"<<mm<<"-"<<yyyy<<" : ";
   }
};


//declare all req. variable
date ob1;
int choice,exday1=0,exday2=0,exday_yr,exday_mn,temp=0,exday=0,count=0,l;
char day[7][6]={"SUN","MON","TUES","WED","THURS","FRI","SAT"};

//chk wheather entered year is leap or not?
int isleap()
{
 if(ob1.chk_lpyr%100==0)
 {
   if(ob1.chk_lpyr%400==0)
   exday2=1;
   else
   exday2=0;
 }
 else
 {
   if(ob1.chk_lpyr%4==0)
   exday2=1;
   else
   exday2=0;
 }
return exday2;
}

//main function
void main()
{
clrscr();

//display menu  for calender
cout<<"----------------\n";
cout<<"  Calender App\n";
cout<<"----------------\n";
cout<<"press 1-goto\n";
cout<<"press 2-exit\n";
cout<<"Enter your choice\n";
cin>>choice;

//for get date from the user
switch(choice)
{
case 1:ob1.getdate();
	break;
case 2: cout<<"thank you for using us\n";
	getch();
	exit(0);
default:cout<<"Invalid Entry\n";
	getch();
	exit(1);
}

//checking for date is valid or not?
if(ob1.yyyy<0)
{
  cout<<"Invalid date\n";
  getch();exit(0);}
else
{
  if(ob1.mm<=0||ob1.mm>12)
  {
   cout<<"Invalid date\n";
   getch();exit(0);
  }
  else
  {
   switch(ob1.mm)
   {
   case 1:
   case 3:
   case 5:
   case 7:
   case 8:
   case 10:
   case 12:if(ob1.dd<1||ob1.dd>31)
	   {
	   cout<<"Invalid date";
	   getch();exit(0);
	   }
   case 4:
   case 6:
   case 9:
   case 11:if(ob1.dd<1||ob1.dd>30)
	   {
	   cout<<"Invalid date";
	   getch();exit(0);
	   }
   case 2: if(isleap()==1)
	   {
	   if(ob1.dd<1||ob1.dd>29)
	   {
	   cout<<"Invalid date";
	   getch();exit(0);
	   }}
	   else
	   {
	   if(ob1.dd<1||ob1.dd>28)
	   {
	   cout<<"Invalid date";
	   getch();exit(0);
	   }

   default:;
  }
 }
}

clrscr();
ob1.putdate();

//calculating extra_days for year
ob1.yyyy--;
ob1.yyyy=ob1.yyyy%400;
exday1=ob1.yyyy/100;
exday1=exday1*5;
ob1.yyyy=ob1.yyyy%100;
exday1=exday1+ob1.yyyy+(ob1.yyyy/4);
exday_yr=exday1;//extra days in year

//calculate extra_days for month & date
ob1.mm--;
switch(ob1.mm)
{
case 1:temp=3;break;
case 2:temp=3+exday2;break;
case 3:temp=6+exday2;break;
case 4:temp=8+exday2;break;
case 5:temp=11+exday2;break;
case 6:temp=13+exday2;break;
case 7:temp=16+exday2;break;
case 8:temp=19+exday2;break;
case 9:temp=21+exday2;break;
case 10:temp=24+exday2;break;
case 11:temp=26+exday2;break;
case 12:temp=29+exday2;break;
}
temp=temp+ob1.dd;
exday_mn=temp; //extra days in month & date

exday=(exday_yr+exday_mn)%7; //extra days till this date...(total extra days)

//print day of that date
switch(exday)
{
case 1:cout<<"Monday";break;
case 2:cout<<"Tuesday";break;
case 3:cout<<"Wednesday";break;
case 4:cout<<"Thursday";break;
case 5:cout<<"Friday";break;
case 6:cout<<"Saturday";break;
case 0:cout<<"Sunday";break;
}

//formating for print calander
cout<<"\n\n\t\t\t--------------\n\t\t\t ";
ob1.mm++;
switch(ob1.mm)
{
case 1:cout<<"JANUARY";break;
case 2:cout<<"FEBRUARY";break;
case 3:cout<<"MARCH";break;
case 4:cout<<"APRIL";break;
case 5:cout<<"MAY";break;
case 6:cout<<"JUNE";break;
case 7:cout<<"JULY";break;
case 8:cout<<"AUGUST";break;
case 9:cout<<"SEPTEMBER";break;
case 10:cout<<"OCTOBER";break;
case 11:cout<<"NOVEMBER";break;
case 12:cout<<"DECEMBER";break;
}
cout<<","<<ob1.chk_lpyr<<endl<<"\t\t\t--------------";

//print days in calender
cout<<endl;
for(int i=0;i<7;i++)
cout<<day[i]<<"\t";
cout<<endl;

/*   calculate extra days according to 1st date of
    that month & print 1st row of calender         */

int z=(exday_yr+exday_mn-ob1.dd+1)%7;
for(int j=1;j<=z;j++)
cout<<"\t";
for(int k=1;k<=7-z;k++)
cout<<k<<"\t";
cout<<"\n";

//printing rest rows of calender
switch(ob1.mm)
{
case 1:
case 3:
case 5:
case 7:
case 8:
case 10:
case 12: for(l=k;l<=31;l++)
	 {
	 count++;
	 cout<<l<<"\t";
	 if(count%7==0)
	 cout<<"\n";
	 }
	 break;
case 4:
case 6:
case 9:
case 11:for(l=k;l<=30;l++)
	 {
	 count++;
	 cout<<l<<"\t";
	 if(count%7==0)
	 cout<<"\n";
	 }
	 break;
case 2: if(exday2==1)
	{
	for(l=k;l<=29;l++)
	 {
	 count++;
	 cout<<l<<"\t";
	 if(count%7==0)
	 cout<<"\n";
	 }
	}
	else
	{
	for(l=k;l<=28;l++)
	 {
	 count++;
	 cout<<l<<"\t";
	 if(count%7==0)
	 cout<<"\n";
	 }
	}
	 break;
default:;
}

getch();
}}