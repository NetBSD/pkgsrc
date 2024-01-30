$NetBSD: patch-src_pulsecore_core-rtclock.c,v 1.2 2024/01/30 13:54:33 ryoon Exp $

macOS build fix: AbsoluteToNanoseconds is long deprecated, and
apparently mach_absolute_time() already returns nanoseconds.

--- src/pulsecore/core-rtclock.c.orig	2024-01-12 17:22:09.000000000 +0000
+++ src/pulsecore/core-rtclock.c
@@ -87,11 +87,7 @@ struct timeval *pa_rtclock_get(struct ti
 
     return tv;
 #elif defined(OS_IS_DARWIN)
-    uint64_t val, abs_time = mach_absolute_time();
-    Nanoseconds nanos;
-
-    nanos = AbsoluteToNanoseconds(*(AbsoluteTime *) &abs_time);
-    val = *(uint64_t *) &nanos;
+    uint64_t val = mach_absolute_time();
 
     tv->tv_sec = val / PA_NSEC_PER_SEC;
     tv->tv_usec = (val % PA_NSEC_PER_SEC) / PA_NSEC_PER_USEC;
