$NetBSD: patch-sql_mysqld.cc,v 1.3 2013/05/06 14:41:08 joerg Exp $

--- sql/mysqld.cc.orig	2013-05-05 21:55:08.000000000 +0000
+++ sql/mysqld.cc
@@ -8268,7 +8268,7 @@ mysqld_get_one_option(int optid,
     opt_myisam_log=1;
     break;
   case (int) OPT_BIN_LOG:
-    opt_bin_log= test(argument != disabled_my_option);
+    opt_bin_log= my_test(argument != disabled_my_option);
     break;
 #ifdef HAVE_REPLICATION
   case (int)OPT_REPLICATE_IGNORE_DB:
@@ -8766,7 +8766,7 @@ static int get_options(int *argc_ptr, ch
     Set some global variables from the global_system_variables
     In most cases the global variables will not be used
   */
-  my_disable_locking= myisam_single_user= test(opt_external_locking == 0);
+  my_disable_locking= myisam_single_user= my_test(opt_external_locking == 0);
   my_default_record_cache_size=global_system_variables.read_buff_size;
 
   global_system_variables.long_query_time= (ulonglong)
@@ -8793,7 +8793,7 @@ static int get_options(int *argc_ptr, ch
 #endif
 
   global_system_variables.engine_condition_pushdown=
-    test(global_system_variables.optimizer_switch &
+    my_test(global_system_variables.optimizer_switch &
          OPTIMIZER_SWITCH_ENGINE_CONDITION_PUSHDOWN);
 
   opt_readonly= read_only;
