$NetBSD: patch-base_clock.cc,v 1.1 2016/05/16 11:51:49 ryoon Exp $

--- base/clock.cc.orig	2016-05-15 08:11:10.000000000 +0000
+++ base/clock.cc
@@ -124,7 +124,7 @@ class ClockImpl : public ClockInterface 
     mach_timebase_info(&timebase_info);
     return static_cast<uint64>(
         1.0e9 * timebase_info.denom / timebase_info.numer);
-#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL)
+#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL) || defined(OS_NETBSD)
     return 1000000uLL;
 #else  // platforms (OS_WIN, OS_MACOSX, OS_LINUX, ...)
 #error "Not supported platform"
@@ -141,7 +141,7 @@ class ClockImpl : public ClockInterface 
     return static_cast<uint64>(timestamp.QuadPart);
 #elif defined(OS_MACOSX)
     return static_cast<uint64>(mach_absolute_time());
-#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL)
+#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL) || defined(OS_NETBSD)
     uint64 sec;
     uint32 usec;
     GetTimeOfDay(&sec, &usec);
