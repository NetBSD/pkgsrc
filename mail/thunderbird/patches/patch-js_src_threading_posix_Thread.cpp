$NetBSD: patch-js_src_threading_posix_Thread.cpp,v 1.1 2018/12/16 08:12:16 ryoon Exp $

--- js/src/threading/posix/Thread.cpp.orig	2018-12-04 23:11:52.000000000 +0000
+++ js/src/threading/posix/Thread.cpp
@@ -194,6 +194,8 @@ js::ThisThread::SetName(const char* name
   rv = 0;
 #elif defined(__NetBSD__)
   rv = pthread_setname_np(pthread_self(), "%s", (void*)name);
+#elif defined(__sun)
+  rv = 0;
 #else
   rv = pthread_setname_np(pthread_self(), name);
 #endif
