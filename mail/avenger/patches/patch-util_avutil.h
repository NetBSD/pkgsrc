$NetBSD: patch-util_avutil.h,v 1.2 2014/11/22 03:01:33 mef Exp $

Fix build on SunOS.

--- util/avutil.h.orig	2008-05-20 20:48:23.000000000 +0200
+++ util/avutil.h	2012-01-27 11:02:13.469861902 +0100
@@ -70,6 +70,13 @@ int clock_gettime (int, struct timespec 
 # define CLOCK_PROF 2
 #endif /* !CLOCK_PROF */
 
+#ifndef HAVE_INT16
+typedef short int16_t;
+#endif /* !HAVE_INT16 */
+#ifndef HAVE_U_INT16
+typedef unsigned short u_int16_t;
+#endif /* !HAVE_U_INT16 */
+
 #ifndef HAVE_INT32_T
 typedef int int32_t;
 #endif /* !HAVE_INT32_T */
