$NetBSD: patch-Python_thread__pthread.h,v 1.2 2023/11/10 09:48:40 nia Exp $

https://bugs.python.org/issue46045
https://trac.macports.org/ticket/59772

--- Python/thread_pthread.h.orig	2023-08-24 17:59:28.000000000 +0000
+++ Python/thread_pthread.h
@@ -78,6 +78,9 @@
    we need to add 0 to make it work there as well. */
 #if (_POSIX_SEMAPHORES+0) == -1
 #define HAVE_BROKEN_POSIX_SEMAPHORES
+#elif defined(__NetBSD__)
+/* XXX accesses to closed file descriptors, needs debugging */
+#define HAVE_BROKEN_POSIX_SEMAPHORES
 #else
 #include <semaphore.h>
 #include <errno.h>
@@ -340,7 +343,17 @@ PyThread_get_thread_native_id(void)
         PyThread_init_thread();
 #ifdef __APPLE__
     uint64_t native_id;
+#if MAC_OS_X_VERSION_MAX_ALLOWED < 1060
+    native_id = pthread_mach_thread_np(pthread_self());
+#elif MAC_OS_X_VERSION_MIN_REQUIRED < 1060
+    if (&pthread_threadid_np != NULL) {
+        (void) pthread_threadid_np(NULL, &native_id);
+    } else {
+        native_id = pthread_mach_thread_np(pthread_self());
+    }
+#else
     (void) pthread_threadid_np(NULL, &native_id);
+#endif
 #elif defined(__linux__)
     pid_t native_id;
     native_id = syscall(SYS_gettid);
