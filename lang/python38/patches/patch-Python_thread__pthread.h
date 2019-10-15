$NetBSD: patch-Python_thread__pthread.h,v 1.1 2019/10/15 16:50:11 adam Exp $

--- Python/thread_pthread.h.orig	2013-05-15 16:33:00.000000000 +0000
+++ Python/thread_pthread.h
@@ -50,6 +50,9 @@
    we need to add 0 to make it work there as well. */
 #if (_POSIX_SEMAPHORES+0) == -1
 #define HAVE_BROKEN_POSIX_SEMAPHORES
+#elif defined(__NetBSD__)
+/* XXX accesses to closed file descriptors, needs debugging */
+#define HAVE_BROKEN_POSIX_SEMAPHORES
 #else
 #include <semaphore.h>
 #include <errno.h>
