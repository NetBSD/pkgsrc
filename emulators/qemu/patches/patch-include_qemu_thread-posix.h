$NetBSD: patch-include_qemu_thread-posix.h,v 1.1 2013/07/09 17:00:58 tsutsui Exp $

make QemuSemaphore.count unsigned per comments on the qemu-devel mailing list:
http://lists.nongnu.org/archive/html/qemu-devel/2013-07/msg00030.html

--- include/qemu/thread-posix.h.orig	2013-06-26 21:47:29.000000000 +0000
+++ include/qemu/thread-posix.h
@@ -15,7 +15,7 @@ struct QemuSemaphore {
 #if defined(__APPLE__) || defined(__NetBSD__)
     pthread_mutex_t lock;
     pthread_cond_t cond;
-    int count;
+    unsigned int count;
 #else
     sem_t sem;
 #endif
