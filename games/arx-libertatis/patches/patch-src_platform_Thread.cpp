$NetBSD: patch-src_platform_Thread.cpp,v 1.2 2021/07/21 12:53:20 yhardy Exp $

Fix pthread_setname_np on NetBSD

--- src/platform/Thread.cpp.orig	2021-07-14 00:04:34.000000000 +0000
+++ src/platform/Thread.cpp
@@ -133,8 +133,13 @@ void * Thread::entryPoint(void * param) 
 	
 	// Set the thread name.
 	#if ARX_HAVE_PTHREAD_SETNAME_NP && ARX_PLATFORM != ARX_PLATFORM_MACOS
+	# if defined(__NetBSD__)
+	// NetBSD
+	pthread_setname_np(thread.m_thread, "%s", (void*)const_cast<char*>(thread.m_threadName.c_str()));
+        # else
 	// Linux
 	pthread_setname_np(thread.m_thread, thread.m_threadName.c_str());
+        # endif
 	#elif ARX_HAVE_PTHREAD_SETNAME_NP && ARX_PLATFORM == ARX_PLATFORM_MACOS
 	// macOS
 	pthread_setname_np(thread.m_threadName.c_str());
