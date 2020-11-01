#include<stdio.h>
#include<stdlib.h>

/*------------------------PRIORITY BASED---------------------------*/

void swap(int *val1,int *val2)
{
	int temp;
	temp=*val1;
	*val1=*val2;
	*val2=temp;	
}

float priority(int n,int bt[20],int pr[20])
{
    int wt[20],tat[20],p[20],i,j,pos,total=0,temp;
	float avg_wt,avg_tat;
    
    for(i=0;i<n;i++)
    {
        p[i]=i+1;         
    }
 
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0;    
 
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=total/n;     
    total=0;
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     
        total+=tat[i];
    }
 	
    avg_tat=total/n;  
    
	return (avg_wt/avg_tat);  
    
}
		/*    Printing   */
		
 void priority_print(int n,int bt[20],int pr[20])
{
	printf("\nMETHOD USED : PRIORITY BASED SCHEDULING\n\n");
	
    int wt[20],tat[20],p[20],i,j,total=0,pos,temp,avg_wt,avg_tat;
    
    for(i=0;i<n;i++)
    {
        p[i]=i+1;         
    }
 
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0;    
 
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=total/n;      
    total=0;
 
    printf("\nProcess\t		  Burst Time    \t	Waiting Time\t	   Turnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     
        total+=tat[i];
        printf("\nProcess[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
    avg_tat=total/n;
    printf("\n\nAverage Waiting Time=%d",avg_wt);
    printf("\nAverage Turnaround Time=%d\n",avg_tat);

 
}


/*--------------FIRST COME FIRST SERVE------------------*/



float fcfs(int n,int at[10],int bt[10])
{
int tat[10]={0},wt[10]={0},ct[10]={0};
int i,sum=0;
float totalTAT=0,totalWT=0;

int j,k;
for(j=0;j<n;j++)
{
    sum+=bt[j];
    ct[j]+=sum;
}
for(k=0;k<n;k++)
{
    tat[k]=ct[k]-at[k];
    totalTAT+=tat[k];
}
for(k=0;k<n;k++)
{
     wt[k]=tat[k]-bt[k];
     totalWT+=wt[k];
}

return ((totalTAT/n) / (totalWT/n));
}

			/*    PRINTING   */
			
void fcfs_print(int n,int at[10],int bt[10])
{
	printf("\nMETHOD USED : FIRST COME FIRST SERVE SCHEDULING\n\n");
	
int tat[10]={0},wt[10]={0},ct[10]={0};
int i,sum=0;
float totalTAT=0,totalWT=0;

int j,k;
for(j=0;j<n;j++)
{
    sum+=bt[j];
    ct[j]+=sum;
}
for(k=0;k<n;k++)
{
    tat[k]=ct[k]-at[k];
    totalTAT+=tat[k];
}
for(k=0;k<n;k++)
{
     wt[k]=tat[k]-bt[k];
     totalWT+=wt[k];
}
printf("Process\t 	AT\t 	BT\t 	CT\t 	TAT\t 	WT\t\n\n");
for(i=0;i<n;i++)
{
     printf("Process%d\t %d\t %d\t %d\t %d\t %d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
}
printf("\nAverage Turnaround Time = %f\n",totalTAT/n);
printf("Average WT = %f\n\n",totalWT/n);

}


/*-------------------SHORTEST JOB FIRST---------------------*/


float shortestjob(int n , int bt[20])
{
      int p[20],wt[20],tat[20],i,j,total=0,pos,temp;
    float avg_wt,avg_tat;
    
 
    for(i=0;i<n;i++)
    {
        p[i]=i+1;
    }
 

    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }
 
        swap(&bt[i],&bt[pos]);
 
        swap(&p[i],&p[pos]);
        
    }
 
    wt[0]=0;
 
 
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=(float)total/n;
    total=0;
 

    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        total+=tat[i];
        
    }
 
    avg_tat=(float)total/n;
    
    return (avg_wt/avg_tat);
}

			/*    PRINTING    */
			
void shortestjob_print(int n , int bt[20])
{
	printf("METHOD USED : SHORTEST JOB FIRST\n\n");
      int p[20],wt[20],tat[20],i,j,total=0,pos,temp;
    float avg_wt,avg_tat;
    
 
    for(i=0;i<n;i++)
    {
        p[i]=i+1;
    }
 

    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }
 
       swap(&bt[i],&bt[pos]);
 
        swap(&p[i],&p[pos]);
        
        
    }
 
    wt[0]=0;
 
 
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=(float)total/n;
    total=0;
 
    printf("\nProcess\t    	  Burst Time    \t	  Waiting Time\t	  Turnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        total+=tat[i];
        printf("\nProcess%d\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
 
    avg_tat=(float)total/n;
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
}

/*-------------------ROUND ROBIN-------------------*/

float roundrobin(int limit ,int arrival_time[10] , int burst_time[10] ,int time_quantum)
{
      int i, total = 0, x, counter = 0;
      int wait_time = 0, turnaround_time = 0, temp[10];
      float average_wait_time, average_turnaround_time;
     
      x = limit;
      for(i = 0; i < limit; i++)
      {
        temp[i] = burst_time[i];
      }
 
      for(total = 0, i = 0; x != 0;)
      {
            if(temp[i] <= time_quantum && temp[i] > 0)
            {
                  total = total + temp[i];
                  temp[i] = 0;
                  counter = 1;
            }
            else if(temp[i] > 0)
            {
                  temp[i] = temp[i] - time_quantum;
                  total = total + time_quantum;
            }
            if(temp[i] == 0 && counter == 1)
            {
                  x--;
                  wait_time = wait_time + total - arrival_time[i] - burst_time[i];
                  turnaround_time = turnaround_time + total - arrival_time[i];
                  counter = 0;
            }
            if(i == limit - 1)
            {
                  i = 0;
            }
            else if(arrival_time[i + 1] <= total)
            {
                  i++;
            }
            else
            {
                  i = 0;
            }
      }
 
      average_wait_time = wait_time * 1.0 / limit;
      average_turnaround_time = turnaround_time * 1.0 / limit;
     
      return (average_wait_time / average_turnaround_time);
}

				/*    PRINTING    */
				
void roundrobin_print(int limit ,int arrival_time[10] , int burst_time[10] ,int time_quantum)
{
	printf("\nMETHOD USED : ROUND ROBIN SCHEDULING\n\n");
	
      int i, total = 0, x, counter = 0;
      int wait_time = 0, turnaround_time = 0, temp[10];
      float average_wait_time, average_turnaround_time;
     
      x = limit;
      for(i = 0; i < limit; i++)
      {
        temp[i] = burst_time[i];
      }
 
      printf("\nProcess ID\t\t	Burst Time\t 	Turnaround Time\t 	Waiting Time\n");
      for(total = 0, i = 0; x != 0;)
      {
            if(temp[i] <= time_quantum && temp[i] > 0)
            {
                  total = total + temp[i];
                  temp[i] = 0;
                  counter = 1;
            }
            else if(temp[i] > 0)
            {
                  temp[i] = temp[i] - time_quantum;
                  total = total + time_quantum;
            }
            if(temp[i] == 0 && counter == 1)
            {
                  x--;
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, burst_time[i], total - arrival_time[i], total - arrival_time[i] - burst_time[i]);
                  wait_time = wait_time + total - arrival_time[i] - burst_time[i];
                  turnaround_time = turnaround_time + total - arrival_time[i];
                  counter = 0;
            }
            if(i == limit - 1)
            {
                  i = 0;
            }
            else if(arrival_time[i + 1] <= total)
            {
                  i++;
            }
            else
            {
                  i = 0;
            }
      }
 
      average_wait_time = wait_time * 1.0 / limit;
      average_turnaround_time = turnaround_time * 1.0 / limit;
      printf("\n\nAverage Waiting Time:\t%f", average_wait_time);
      printf("\nAvg Turnaround Time:\t%f\n", average_turnaround_time);
      
}


/*------------------------DRIVER CODE-----------------------*/

int main()
{
	int n,i,pos;
	float min=1000.0;
    printf("\nOur Methods:\n");
	printf("1.Priority Scheduling\n");
    printf("2.First Come First Serve\n");
    printf("3.Round Robin Scheduling\n");
    printf("4.Shortest Job First\n");
                
    printf("\nEnter number of Processes: ");
    scanf("%d",&n);
    
    int Arr_time[n],Arr_time2[n],Arr_time3[n];
    
	int Burst_time[n],Burst_time2[n],Burst_time3[n],Burst_time4[n],Burst_time5[n];
	
	int Priority[n],Priority2[n];
	
	int Time_qtm;
    printf("Please provide the following details:\n");
    for(i=0;i<n;i++)
    {
    	printf("\nPROCESS %d",i+1);
    	
    	printf("\nArrival Time:\t");
 	    scanf("%d", &Arr_time[i]);
 	    Arr_time2[i]=Arr_time[i];
 	    Arr_time3[i]=Arr_time[i];
 	  
 	    
        printf("Burst Time:\t");
 		scanf("%d", &Burst_time[i]);
 		Burst_time2[i]=Burst_time[i];
 		Burst_time3[i]=Burst_time[i];
 		Burst_time4[i]=Burst_time[i];
 		Burst_time5[i]=Burst_time[i];
 		
 		printf("Priority:\t");
 		scanf("%d", &Priority[i]);
 		Priority2[i]=Priority[i];
 	
	}
	printf("\nEnter Time Quantum:\t");
    scanf("%d", &Time_qtm);
    
	float Avg_time1,Avg_time2,Avg_time3,Avg_time4;
	
	Avg_time1 = priority(n,Burst_time,Priority);
	Avg_time2 = fcfs(n,Arr_time,Burst_time2);
	Avg_time3 = shortestjob(n,Burst_time3);
	Avg_time4 = roundrobin(n,Arr_time2,Burst_time4,Time_qtm);
	
	float compare[4] = {Avg_time1,Avg_time2,Avg_time3};
	
	for(i=0;i<3;i++)
	{
		if (compare[i]<min)
		{
			min = compare[i];
			pos = i;
		}
	}
	if ( pos == 0 )
	{
		priority_print(n,Burst_time5,Priority2);
	}
	
	if ( pos == 1 )
	{
		fcfs_print(n,Arr_time3,Burst_time5);
	}
	
	if ( pos == 2 )
	{
		shortestjob_print(n,Burst_time5);	
	}
	
	if ( pos == 3 )
	{
		roundrobin_print(n,Arr_time3,Burst_time5,Time_qtm);
	}
   
    return 0;
}

			/*--------------------------THANK YOU--------------------------*/
