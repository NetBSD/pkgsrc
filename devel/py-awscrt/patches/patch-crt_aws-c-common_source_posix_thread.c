$NetBSD: patch-crt_aws-c-common_source_posix_thread.c,v 1.1 2025/09/07 18:33:59 maya Exp $

Fix NetBSD build issue: no pthread_np.h header file

--- crt/aws-c-common/source/posix/thread.c.orig	2025-09-06 20:32:43.639391780 +0000
+++ crt/aws-c-common/source/posix/thread.c
@@ -23,7 +23,7 @@
 #include <time.h>
 #include <unistd.h>
 
-#if defined(__FreeBSD__) || defined(__NetBSD__)
+#if defined(__FreeBSD__)
 #    include <pthread_np.h>
 typedef cpuset_t cpu_set_t;
 #elif defined(__OpenBSD__)
