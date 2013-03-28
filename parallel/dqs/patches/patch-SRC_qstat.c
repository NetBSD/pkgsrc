$NetBSD: patch-SRC_qstat.c,v 1.1 2013/03/28 21:37:24 joerg Exp $

--- SRC/qstat.c.orig	2013-03-28 16:23:29.000000000 +0000
+++ SRC/qstat.c
@@ -114,6 +114,9 @@ char *dqs_ctime();
 #include "globals.h"
 #include "dqs_errno.h"
 
+static void dqs_print_job(dqs_job_type *qstat_conf, char *master, dqs_job_type *job, string qname);
+static void dqs_qstat_print_queue(dqs_job_type *qstat_conf, dqs_queue_type *q);
+
 int              q_suitability=0;
 int              j_suitability=0;
 int              l_suitability=0;
@@ -375,10 +378,7 @@ main(argc, argv,envp)
 } 
 
 /***************************************************************************/
-int dqs_qstat_print_queue(qstat_conf,q)
-     dqs_job_type *qstat_conf;
-     dqs_queue_type *q;
-     
+static void dqs_qstat_print_queue(dqs_job_type *qstat_conf, dqs_queue_type *q)
 {
   
   float         load_avg;
@@ -437,12 +437,7 @@ int dqs_qstat_print_queue(qstat_conf,q)
 }
 
 /***************************************************************************/
-int dqs_print_job(qstat_conf,master,job, qname)
-     dqs_job_type *qstat_conf;
-     char         *master;
-     dqs_job_type *job;
-     string qname;
-     
+static void dqs_print_job(dqs_job_type *qstat_conf, char *master, dqs_job_type *job, string qname)
 {
   dqs_list_type *lp3;
   string job_name;
