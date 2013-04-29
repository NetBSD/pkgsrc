$NetBSD: patch-sql-common_client.c,v 1.1 2013/04/29 21:16:56 joerg Exp $

--- sql-common/client.c.orig	2013-04-28 13:57:28.000000000 +0000
+++ sql-common/client.c
@@ -1289,7 +1289,7 @@ void mysql_read_default_options(struct s
           options->secure_auth= TRUE;
           break;
         case OPT_report_data_truncation:
-          options->report_data_truncation= opt_arg ? test(atoi(opt_arg)) : 1;
+          options->report_data_truncation= opt_arg ? my_test(atoi(opt_arg)) : 1;
           break;
         case OPT_plugin_dir:
           {
@@ -4296,7 +4296,7 @@ mysql_options(MYSQL *mysql,enum mysql_op
     mysql->options.protocol=MYSQL_PROTOCOL_PIPE; /* Force named pipe */
     break;
   case MYSQL_OPT_LOCAL_INFILE:			/* Allow LOAD DATA LOCAL ?*/
-    if (!arg || test(*(uint*) arg))
+    if (!arg || my_test(*(uint*) arg))
       mysql->options.client_flag|= CLIENT_LOCAL_FILES;
     else
       mysql->options.client_flag&= ~CLIENT_LOCAL_FILES;
@@ -4342,7 +4342,7 @@ mysql_options(MYSQL *mysql,enum mysql_op
     mysql->options.secure_auth= *(my_bool *) arg;
     break;
   case MYSQL_REPORT_DATA_TRUNCATION:
-    mysql->options.report_data_truncation= test(*(my_bool *) arg);
+    mysql->options.report_data_truncation= my_test(*(my_bool *) arg);
     break;
   case MYSQL_OPT_RECONNECT:
     mysql->reconnect= *(my_bool *) arg;
