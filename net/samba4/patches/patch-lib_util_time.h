$NetBSD: patch-lib_util_time.h,v 1.2 2022/10/25 07:46:11 wiz Exp $

Define timeval/timespec.

--- lib/util/time.h.orig	2022-08-08 14:15:39.172190700 +0000
+++ lib/util/time.h
@@ -29,6 +29,18 @@
 #include <talloc.h>
 #include <time.h>
 
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
