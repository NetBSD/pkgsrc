$NetBSD: patch-sql_mysqld.cc,v 1.1 2011/08/02 16:15:08 taca Exp $

* Handling of time_t: http://lists.mysql.com/commits/128103

--- sql/mysqld.cc.orig	2011-01-25 11:27:51.000000000 +0000
+++ sql/mysqld.cc
@@ -2836,13 +2836,6 @@ static int init_common_variables(const c
   max_system_variables.pseudo_thread_id= (ulong)~0;
   server_start_time= flush_status_time= time((time_t*) 0);
   
-  /* TODO: remove this when my_time_t is 64 bit compatible */
-  if (server_start_time >= (time_t) MY_TIME_T_MAX)
-  {
-    sql_print_error("This MySQL server doesn't support dates later then 2038");
-    return 1;
-  }
-
   if (init_thread_environment())
     return 1;
   mysql_init_variables();
@@ -2882,6 +2875,13 @@ static int init_common_variables(const c
   mysql_slow_log.init_pthread_objects();
   mysql_bin_log.init_pthread_objects();
 
+  /* TODO: remove this when my_time_t is 64 bit compatible */
+  if (!IS_VALID_TIME_T(server_start_time))
+  {
+    sql_print_error("This MySQL server doesn't support dates later then 2038");
+    return 1;
+  }
+
   if (gethostname(glob_hostname,sizeof(glob_hostname)) < 0)
   {
     strmake(glob_hostname, STRING_WITH_LEN("localhost"));
