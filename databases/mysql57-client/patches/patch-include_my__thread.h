$NetBSD: patch-include_my__thread.h,v 1.1 2016/09/16 06:49:11 adam Exp $

--- include/my_thread.h.orig	2016-03-28 18:06:12.000000000 +0000
+++ include/my_thread.h
@@ -24,6 +24,13 @@
 #include <pthread.h>
 #endif
 
+/* defines __NetBSD_Version__ */
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#endif
+
+#include <signal.h>
+
 #ifndef ETIME
 #define ETIME ETIMEDOUT             /* For FreeBSD */
 #endif
