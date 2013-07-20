$NetBSD: patch-base_util.cc,v 1.2 2013/07/20 04:34:53 ryoon Exp $

--- base/util.cc.orig	2013-07-17 02:38:04.000000000 +0000
+++ base/util.cc
@@ -1087,15 +1087,15 @@ class ClockImpl : public Util::ClockInte
     mach_timebase_info(&timebase_info);
     return static_cast<uint64>(
         1.0e9 * timebase_info.denom / timebase_info.numer);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_NETBSD)
 #if defined(HAVE_LIBRT)
     return 1000000000uLL;
 #else  // HAVE_LIBRT
     return 1000000uLL;
 #endif  // HAVE_LIBRT
-#else  // platforms (OS_WIN, OS_MACOSX, OS_LINUX, ...)
+#else  // platforms (OS_WIN, OS_MACOSX, OS_LINUX, OS_NETBSD, ...)
 #error "Not supported platform"
-#endif  // platforms (OS_WIN, OS_MACOSX, OS_LINUX, ...)
+#endif  // platforms (OS_WIN, OS_MACOSX, OS_LINUX, OS_NETBSD. ...)
   }
 
   virtual uint64 GetTicks() {
@@ -1107,7 +1107,7 @@ class ClockImpl : public Util::ClockInte
     return static_cast<uint64>(timestamp.QuadPart);
 #elif defined(OS_MACOSX)
     return static_cast<uint64>(mach_absolute_time());
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_NETBSD)
 #if defined(HAVE_LIBRT)
     struct timespec timestamp;
     if (-1 == clock_gettime(CLOCK_REALTIME, &timestamp)) {
