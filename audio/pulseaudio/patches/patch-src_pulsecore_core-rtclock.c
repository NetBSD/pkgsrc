$NetBSD: patch-src_pulsecore_core-rtclock.c,v 1.1 2021/09/17 06:47:30 schmonz Exp $

macOS build fix: AbsoluteToNanoseconds is long deprecated, and
apparently mach_absolute_time() already returns nanoseconds.

--- src/pulsecore/core-rtclock.c.orig	2021-07-27 20:02:27.000000000 +0000
+++ src/pulsecore/core-rtclock.c
@@ -66,11 +66,7 @@ pa_usec_t pa_rtclock_age(const struct ti
 struct timeval *pa_rtclock_get(struct timeval *tv) {
 
 #if defined(OS_IS_DARWIN)
-    uint64_t val, abs_time = mach_absolute_time();
-    Nanoseconds nanos;
-
-    nanos = AbsoluteToNanoseconds(*(AbsoluteTime *) &abs_time);
-    val = *(uint64_t *) &nanos;
+    uint64_t val = mach_absolute_time();
 
     tv->tv_sec = val / PA_NSEC_PER_SEC;
     tv->tv_usec = (val % PA_NSEC_PER_SEC) / PA_NSEC_PER_USEC;
