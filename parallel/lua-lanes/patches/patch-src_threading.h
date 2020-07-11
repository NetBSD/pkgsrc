$NetBSD: patch-src_threading.h,v 1.1 2020/07/11 16:15:09 nia Exp $

NetBSD support.

--- src/threading.h.orig	2018-11-30 12:28:50.000000000 +0000
+++ src/threading.h
@@ -143,7 +143,7 @@ enum e_status { PENDING, RUNNING, WAITIN
   //
   #if defined( PLATFORM_OSX)
     #define YIELD() pthread_yield_np()
-#elif defined( PLATFORM_WIN32) || defined( PLATFORM_POCKETPC) || defined(__ANDROID__) // no PTHREAD for PLATFORM_XBOX
+#elif defined( PLATFORM_WIN32) || defined( PLATFORM_POCKETPC) || defined(__ANDROID__) || defined(__NetBSD__) // no PTHREAD for PLATFORM_XBOX
     // for some reason win32-pthread doesn't have pthread_yield(), but sched_yield()
     #define YIELD() sched_yield()
   #else
