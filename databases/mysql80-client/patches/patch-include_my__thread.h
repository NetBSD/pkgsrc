$NetBSD: patch-include_my__thread.h,v 1.1 2021/05/13 15:25:20 jdolecek Exp $

--- include/my_thread.h.orig	2019-12-09 19:53:17.000000000 +0000
+++ include/my_thread.h
@@ -39,6 +39,13 @@
 #include "my_inttypes.h"
 #include "my_macros.h"
 
+/* defines __NetBSD_Version__ */
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#endif
+
+#include <signal.h>
+
 #ifndef ETIME
 #define ETIME ETIMEDOUT /* For FreeBSD */
 #endif
