$NetBSD: patch-sql_set__var.cc,v 1.1 2011/08/02 16:15:08 taca Exp $

* Handling of time_t: http://lists.mysql.com/commits/128103

--- sql/set_var.cc.orig	2011-01-25 11:27:51.000000000 +0000
+++ sql/set_var.cc
@@ -2717,7 +2717,10 @@ bool sys_var_timestamp::check(THD *thd, 
   time_t val;
   var->save_result.ulonglong_value= var->value->val_int();
   val= (time_t) var->save_result.ulonglong_value;
-  if (val < (time_t) MY_TIME_T_MIN || val > (time_t) MY_TIME_T_MAX)
+  if ((val < TIMESTAMP_MIN_VALUE)
+#if SIZEOF_TIME_T > 4
+      || (val > TIMESTAMP_MAX_VALUE))
+#endif)
   {
     my_message(ER_UNKNOWN_ERROR, 
                "This version of MySQL doesn't support dates later than 2038",
