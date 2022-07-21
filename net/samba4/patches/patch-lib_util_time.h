$NetBSD: patch-lib_util_time.h,v 1.1 2022/07/21 09:35:50 adam Exp $

Define timeval/timespec.

--- lib/util/time.h.orig	2022-07-20 13:08:26.333843041 +0000
+++ lib/util/time.h
@@ -28,6 +28,18 @@
 #include <stdint.h>
 #include <talloc.h>
 
+/* From "system/time.h" */
+#ifdef TIME_WITH_SYS_TIME
+#include <sys/time.h>
+#include <time.h>
+#else
+#ifdef HAVE_SYS_TIME_H
+#include <sys/time.h>
+#else
+#include <time.h>
+#endif
+#endif
+
 #ifndef TIME_T_MIN
 /* we use 0 here, because (time_t)-1 means error */
 #define TIME_T_MIN 0
