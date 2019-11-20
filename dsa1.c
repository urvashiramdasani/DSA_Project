#include<stdio.h>
#include<string.h>
#define MAX 20

//TOPOLOGICAL SORT IMPLEMENTATION
//DAG-DIRECTED ACYCLIC GRAPH
int n,adj[MAX][MAX];
int front=-1,rear=-1,queue[MAX];
int i,j=0,k,choice;
int topsort[MAX],indeg[MAX];

//FUNCTION TO CREATE GRAPH
void create_graph_job_scheduling()
{

	int origin,destin;
	int i,max_edges;

    //TO SCAN NO. OF VERTICES
	printf("Enter the number of jobs : ");
	scanf("%d",&n);
	max_edges=n*(n-1);

	//ASSIGNING JOB TO EVERY VERTICES
	char jobs[n][50];
	printf("\nEnter Your Jobs : ");
	for(i=0;i<n;i++) {
		printf("\nJob %d : ",i+1);
		scanf("%s",&jobs[i]);
	}

	//TAKING INPUT FOR PATH FROM ONE JOB TO ANOTHER
	for(i=1;i<=max_edges;i++)
	{

		printf("Enter dependencies of job %d(0 0 to quit): ",i);
		scanf("%d %d",&origin,&destin);

		if((origin==0) && (destin==0))
			break;

		if( origin > n || destin > n || origin<=0 || destin<=0)
		{
			printf("Invalid edge!\n");
			i--;
		}
		else
			adj[origin][destin]=1;
	}/*End of for*/
}/*End of create_graph()*/

void create_graph_interior_of_house()
{

	int origin,destin;
	int i,max_edges;

    //TO SCAN NO. OF VERTICES
	printf("Enter the number of features you want to construct : ");
	scanf("%d",&n);
	max_edges=n*(n-1);

	//ASSIGNING JOB TO EVERY VERTICES
	char jobs[n][50];
	printf("\nEnter the tasks needed to be performed : ");
	for(i=0;i<n;i++) {
    printf("\nTask %d : ",i+1);
		scanf("%s",&jobs[i]);
	}

	//TAKING INPUT FOR PATH FROM ONE JOB TO ANOTHER
	for(i=1;i<=max_edges;i++)
	{

		printf("Enter dependencies of tasks %d(0 0 to quit): ",i);
		scanf("%d %d",&origin,&destin);

		if((origin==0) && (destin==0))
			break;

		if( origin > n || destin > n || origin<=0 || destin<=0)
		{
			printf("Invalid edge!\n");
			i--;
		}
		else
			adj[origin][destin]=1;
	}/*End of for*/
}/*End of create_graph()*/

void create_graph_course_prerequisite()
{

	int origin,destin;
	int i,max_edges;

    //TO SCAN NO. OF VERTICES
	printf("Enter the total number of courses (courses + prerequisites) : ");
	scanf("%d",&n);
	max_edges=n*(n-1);

	//ASSIGNING JOB TO EVERY VERTICES
	char jobs[n][50];
	printf("\nEnter the names : ");
	for(i=0;i<n;i++) {
		printf("\nName %d : ",i+1);
		scanf("%s",&jobs[i]);
	}

	//TAKING INPUT FOR PATH FROM ONE JOB TO ANOTHER
	for(i=1;i<=max_edges;i++)
	{

		printf("Enter relations among courses %d(0 0 to quit): ",i);
		scanf("%d %d",&origin,&destin);

		if((origin==0) && (destin==0))
			break;

		if( origin > n || destin > n || origin<=0 || destin<=0)
		{
			printf("Invalid edge!\n");
			i--;
		}
		else
			adj[origin][destin]=1;
	}/*End of for*/
}/*End of create_graph()*/

//MAIN MENU OF SORT
void front_page_job_scheduling() {
	printf("\n\t\t######################################################\n");
	printf("\n\t\t\tWelcome to Job Scheduling Company\n ");
	printf("\n\t\t######################################################\n");
	printf("\n\n\t\tWe are here to schedule your Routine for you ");
	printf("\n\t\tin a manner that you don't end up in a mess while you work!");
	printf("\n\n\t\t------------------------------------------------------------\n");
}

void front_page_interior_of_house() {
	printf("\n\t\t######################################################\n");
	printf("\n\t\t\tWelcome to Nirma Interior Design Company\n ");
	printf("\n\t\t######################################################\n");
	printf("\n\n\t\tWe are here to provide procedure to design your house for you ");
	printf("\n\t\tin a manner that you don't end up in a mess \n\t\twhile you work!");
	printf("\n\n\t\t------------------------------------------------------------\n");
}

void front_page_course_prerequisite() {
	printf("\n\t\t######################################################\n");
	printf("\n\t\t\tWelcome to Nirma online Courses\n ");
	printf("\n\t\t######################################################\n");
	printf("\n\n\t\tWe are here to suggest you best course for you ");
	printf("\n\t\ton the basic of your abilities!");
	printf("\n\n------------------------------------------------------------\n");
}

//DISPLAY METHOD TO SHOW THE SORTED VERTICES
void display()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%3d",adj[i][j]);
		printf("\n");
	}
}/*End of display()*/

//METHOD TO ENTER VERTICES IN QUEUE IN ACCESSDING ORDER OF IN-DEGREE OF VERTICES
void insert_queue(int node)
{
	if (rear==MAX-1)
		printf("Queue Overflow\n");
	else
	   {
		if (front==-1)  /*If queue is initially empty */
			front=0;
		rear=rear+1;
		queue[rear] = node ;
	   }
}/*End of insert_queue()*/

//TO DELETE THE VERTEX FROM THE QUEUE
int delete_queue()
{
	int del_item;
	if (front == -1 || front > rear)
	{
		printf("Queue Underflow\n");
		return 0;
	}
	else
	{
		del_item=queue[front];
		front=front+1;
		return del_item;
	}
}/*End of delete_queue() */

//CODE TO CALCULATE IN-DEGREE OF EVERY VERTEX
int indegree(int node)
{
	int i,in_deg=0;
	for(i=1;i<=n;i++)
		if( adj[i][node] == 1 )
			in_deg++;
	return in_deg;
}/*End of indegree() */

//CODE TO PERFORM TOPOLOGICAL SORTING OF VERTICES
int calculate() {
	int i,j=0,k;
	for(i=1;i<=n;i++)
	{
		indeg[i]=indegree(i);
		if( indeg[i]==0 )
			insert_queue(i);
	}

	while(front<=rear) /*Loop till queue is not empty */
	{
		k=delete_queue();
		topsort[j++]=k; /*Add node k to topsort array*/
		/*Delete all edges going fron node k */
		for(i=1;i<=n;i++)
		{
			if(  adj[k][i]==1  )
			{
				adj[k][i]=0;
				indeg[i]=indeg[i]-1;
				if(indeg[i]==0)
					insert_queue(i);
			}
		}/*End of for*/
	}/*End of while*/
	return j;
}

//MAIN METHOD
void main()
{
	int j;
  printf("\n\t\t\t------------- WELCOME TO FAST-DIAL APP ---------------\n");
  printf("\n\t\t\tThe Only Place to Find Solutions to all your problems..!\n\n");
  
	  do{
		    printf("\t\t###############################################################\n");
			printf("\t\t\t\t\tAVAILABLE SERVICES\n");
			printf("\t\t###############################################################\n");
			printf("\n\t\tPlease Enter Your Choice :\n ");
			printf("\t\t\t1.JOB SCHEDULING\n\t\t\t2.INTERIOR OF HOUSE\n\t\t\t3.COURSE PREREQUESITE\n\t\t\t4.EXIT\n");
			scanf("%d",&choice);
    switch(choice)
	{
		case 1: front_page_job_scheduling();
		        create_graph_job_scheduling();
				printf("\n");
				printf("The adjacency matrix is :\n");
				display();
				j = calculate();
				printf("\n");
				printf("The Least time consuming order of jobs  :\n");
				for(i=0;i<j;i++)
				{
				printf( "%d ",topsort[i] );}
				printf("\n\n");
				break;

		case 2: front_page_interior_of_house();
		       create_graph_interior_of_house();
				printf("\n");
				printf("The adjacency matrix is :\n");
				display();
				j = calculate();
				printf("\n");
				printf("The Least time consuming order of jobs  :\n");
				for(i=0;i<j;i++)
				{
				printf( "%d ",topsort[i] );}
				printf("\n\n");
				break;

		case 3: front_page_course_prerequisite();
		        create_graph_course_prerequisite();
				printf("\n");
				printf("The adjacency matrix is :\n");
				display();
				j = calculate();
				printf("\n");
				printf("The Least time consuming order of jobs  :\n");
				for(i=0;i<j;i++)
				{
				printf( "%d ",topsort[i] );}
				printf("\n\n");
				break;

		case 4: choice = 4;
            break;
    default: printf("\nInvalid Choice...");
            break;
	}
	}while(choice !=4);
}/*End of main()*/