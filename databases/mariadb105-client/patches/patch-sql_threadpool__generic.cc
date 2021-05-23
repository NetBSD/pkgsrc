$NetBSD: patch-sql_threadpool__generic.cc,v 1.1 2021/05/23 15:32:47 nia Exp $

Deal with kqueue changes in NetBSD 10.

--- sql/threadpool_generic.cc.orig	2021-05-05 21:00:19.000000000 +0000
+++ sql/threadpool_generic.cc
@@ -240,7 +240,12 @@ static void *native_event_get_userdata(n
 */
 
 #ifdef __NetBSD__
+#include <sys/param.h>
+#  if __NetBSD_Prereq__(9,99,17)
+#define MY_EV_SET(a, b, c, d, e, f, g) EV_SET(a, b, c, d, e, f, g)
+#  else
 #define MY_EV_SET(a, b, c, d, e, f, g) EV_SET(a, b, c, d, e, f, (intptr_t)g)
+#  endif
 #else
 #define MY_EV_SET(a, b, c, d, e, f, g) EV_SET(a, b, c, d, e, f, g)
 #endif
