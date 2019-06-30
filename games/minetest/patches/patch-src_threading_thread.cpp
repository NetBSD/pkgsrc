$NetBSD: patch-src_threading_thread.cpp,v 1.1 2019/06/30 22:27:22 nia Exp $

There must be a format string argument for pthread_setname_np.

--- src/threading/thread.cpp.orig	2019-03-31 20:57:45.000000000 +0000
+++ src/threading/thread.cpp
@@ -219,7 +219,7 @@ void Thread::setName(const std::string &
 
 #elif defined(__NetBSD__)
 
-	pthread_setname_np(pthread_self(), name.c_str());
+	pthread_setname_np(pthread_self(), "%s", (char *)name.c_str());
 
 #elif defined(__APPLE__)
 
