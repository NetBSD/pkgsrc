$NetBSD: patch-include_my__thread.h,v 1.1 2022/04/17 04:07:14 jnemeth Exp $

--- include/my_thread.h.orig	2021-09-14 09:08:08.000000000 +0000
+++ include/my_thread.h
@@ -31,6 +31,13 @@
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
