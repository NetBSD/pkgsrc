$NetBSD: patch-js_src_threading_posix_Thread.cpp,v 1.1 2018/05/11 19:18:35 jperkin Exp $

Support SunOS.

--- js/src/threading/posix/Thread.cpp.orig	2018-04-28 01:04:03.000000000 +0000
+++ js/src/threading/posix/Thread.cpp
@@ -159,6 +159,8 @@ js::ThisThread::SetName(const char* name
   rv = 0;
 #elif defined(__NetBSD__)
   rv = pthread_setname_np(pthread_self(), "%s", (void*)name);
+#elif defined(__sun)
+  rv = 0;
 #else
   rv = pthread_setname_np(pthread_self(), name);
 #endif
