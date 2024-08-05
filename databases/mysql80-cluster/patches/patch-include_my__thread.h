$NetBSD: patch-include_my__thread.h,v 1.1 2024/08/05 01:23:59 jnemeth Exp $

--- include/my_thread.h.orig	2022-03-23 13:49:36.000000000 +0000
+++ include/my_thread.h
@@ -39,6 +39,12 @@
 #include "my_inttypes.h"
 #include "my_macros.h"
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#endif
+
+#include <signal.h>
+
 #ifndef ETIME
 #define ETIME ETIMEDOUT /* For FreeBSD */
 #endif
