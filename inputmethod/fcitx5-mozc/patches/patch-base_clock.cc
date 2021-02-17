$NetBSD: patch-base_clock.cc,v 1.1 2021/02/17 15:29:51 ryoon Exp $

* NetBSD support

--- base/clock.cc.orig	2021-02-15 03:48:53.000000000 +0000
+++ base/clock.cc
@@ -116,7 +116,7 @@ class ClockImpl : public ClockInterface 
     mach_timebase_info(&timebase_info);
     return static_cast<uint64>(1.0e9 * timebase_info.denom /
                                timebase_info.numer);
-#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_WASM)
+#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_WASM) || defined(OS_NETBSD)
     return 1000000uLL;
 #else  // platforms (OS_WIN, __APPLE__, OS_LINUX, ...)
 #error "Not supported platform"
@@ -133,7 +133,7 @@ class ClockImpl : public ClockInterface 
     return static_cast<uint64>(timestamp.QuadPart);
 #elif defined(__APPLE__)
     return static_cast<uint64>(mach_absolute_time());
-#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_WASM)
+#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_WASM) || defined(OS_NETBSD)
     uint64 sec;
     uint32 usec;
     GetTimeOfDay(&sec, &usec);
