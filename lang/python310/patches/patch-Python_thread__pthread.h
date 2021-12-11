$NetBSD: patch-Python_thread__pthread.h,v 1.2 2021/12/11 10:40:58 wiz Exp $

https://bugs.python.org/issue46045

--- Python/thread_pthread.h.orig	2013-05-15 16:33:00.000000000 +0000
+++ Python/thread_pthread.h
@@ -82,6 +82,9 @@
    we need to add 0 to make it work there as well. */
 #if (_POSIX_SEMAPHORES+0) == -1
 #define HAVE_BROKEN_POSIX_SEMAPHORES
+#elif defined(__NetBSD__)
+/* XXX accesses to closed file descriptors, needs debugging */
+#define HAVE_BROKEN_POSIX_SEMAPHORES
 #else
 #include <semaphore.h>
 #include <errno.h>
