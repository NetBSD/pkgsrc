$NetBSD: patch-sql-common_my__time.c,v 1.1 2011/08/02 16:15:08 taca Exp $

* Handling of time_t: http://lists.mysql.com/commits/128103

--- sql-common/my_time.c.orig	2011-01-25 11:28:00.000000000 +0000
+++ sql-common/my_time.c
@@ -984,8 +984,16 @@ my_system_gmt_sec(const MYSQL_TIME *t_sr
     So, tmp < TIMESTAMP_MIN_VALUE will be triggered. On platfroms
     with unsigned time_t tmp+= shift*86400L might result in a number,
     larger then TIMESTAMP_MAX_VALUE, so another check will work.
+
+    tmp being larger than TIMESTAMP_MAX_VALUE can only happen on
+    platforms where the size of time_t is larger than the size of
+    TIMESTAMP_MAX_VALUE (currently INT32 : 4 bytes).
+    #ifdef to avoid the compilation warnings on these platforms (OpenBSD).
   */
-  if ((tmp < TIMESTAMP_MIN_VALUE) || (tmp > TIMESTAMP_MAX_VALUE))
+  if ((tmp < TIMESTAMP_MIN_VALUE)
+#if SIZEOF_TIME_T > 4
+      || (tmp > TIMESTAMP_MAX_VALUE))
+#endif
     tmp= 0;
 
   return (my_time_t) tmp;
