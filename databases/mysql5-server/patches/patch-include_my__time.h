$NetBSD: patch-include_my__time.h,v 1.1 2011/08/02 16:15:08 taca Exp $

* Handling of time_t: http://lists.mysql.com/commits/128103

--- include/my_time.h.orig	2011-01-25 11:28:00.000000000 +0000
+++ include/my_time.h
@@ -44,6 +44,17 @@ typedef long my_time_t;
 #define MY_TIME_T_MIN LONG_MIN
 
 
+/*
+  check for valid times only if the range of time_t is greater than
+  the range of my_time_t
+*/
+#if SIZEOF_TIME_T > SIZEOF_LONG
+# define IS_VALID_TIME_T(x) ((x) <= (time_t) MY_TIME_T_MAX && \
+			     (x) >= (time_t) MY_TIME_T_MIN)
+#else
+# define IS_VALID_TIME_T(x) (1 > 0)
+#endif
+
 /* Time handling defaults */
 #define TIMESTAMP_MAX_YEAR 2038
 #define YY_PART_YEAR	   70
