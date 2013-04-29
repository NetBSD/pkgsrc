$NetBSD: patch-base_util.cc,v 1.2 2013/04/29 09:21:24 ryoon Exp $

--- base/util.cc.orig	2013-03-29 04:33:43.000000000 +0000
+++ base/util.cc
@@ -932,7 +932,7 @@ class ClockImpl : public Util::ClockInte
     mach_timebase_info(&timebase_info);
     return static_cast<uint64>(
         1.0e9 * timebase_info.denom / timebase_info.numer);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_NETBSD)
 #if defined(HAVE_LIBRT)
     return 1000000000uLL;
 #else  // HAVE_LIBRT
@@ -952,7 +952,7 @@ class ClockImpl : public Util::ClockInte
     return static_cast<uint64>(timestamp.QuadPart);
 #elif defined(OS_MACOSX)
     return static_cast<uint64>(mach_absolute_time());
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_NETBSD)
 #if defined(HAVE_LIBRT)
     struct timespec timestamp;
     if (-1 == clock_gettime(CLOCK_REALTIME, &timestamp)) {
