$NetBSD: patch-js_src_threading_posix_PosixThread.cpp,v 1.1 2020/12/06 10:50:03 nia Exp $

illumos pthreads don't have pthread_setname_np.

--- js/src/threading/posix/PosixThread.cpp.orig	2020-11-04 10:52:03.000000000 +0000
+++ js/src/threading/posix/PosixThread.cpp
@@ -103,6 +103,8 @@ void ThisThread::SetName(const char* nam
   rv = 0;
 #elif defined(__NetBSD__)
   rv = pthread_setname_np(pthread_self(), "%s", (void*)name);
+#elif defined(__sun)
+  rv = 0;
 #else
   rv = pthread_setname_np(pthread_self(), name);
 #endif
