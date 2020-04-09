$NetBSD: patch-threading_posix_Thread.cpp,v 1.1 2020/04/09 09:40:47 jperkin Exp $

Fix build on SunOS/x86_64.

--- threading/posix/Thread.cpp.orig	2019-07-01 09:07:44.000000000 +0000
+++ threading/posix/Thread.cpp
@@ -160,6 +160,8 @@ void js::ThisThread::SetName(const char*
   rv = 0;
 #elif defined(__NetBSD__)
   rv = pthread_setname_np(pthread_self(), "%s", (void*)name);
+#elif defined(__sun)
+  rv = 0; 
 #else
   rv = pthread_setname_np(pthread_self(), name);
 #endif
