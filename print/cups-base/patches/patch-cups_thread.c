$NetBSD: patch-cups_thread.c,v 1.3 2021/02/06 15:22:58 dbj Exp $

Patch for macOS Sierra and before.

--- cups/thread.c.orig	2020-04-27 11:04:29.000000000 -0700
+++ cups/thread.c	2020-12-05 18:07:53.000000000 -0800
@@ -14,6 +14,27 @@
 #include "cups-private.h"
 #include "thread-private.h"
 
+#if __APPLE__ && __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ < 101200
+#include <mach/mach_time.h>
+#ifndef CLOCK_REALTIME
+#define CLOCK_REALTIME 0
+#define CLOCK_MONOTONIC 0
+#endif
+#define clock_gettime cups_thread_static_clock_gettime
+static int
+clock_gettime(int clk_id, struct timespec *t){
+    mach_timebase_info_data_t timebase;
+    mach_timebase_info(&timebase);
+    uint64_t time;
+    time = mach_absolute_time();
+    double nseconds = ((double)time * (double)timebase.numer)/((double)timebase.denom);
+    double seconds = ((double)time * (double)timebase.numer)/((double)timebase.denom * 1e9);
+    t->tv_sec = seconds;
+    t->tv_nsec = nseconds;
+    return 0;
+}
+#endif
+
 
 #if defined(HAVE_PTHREAD_H)
 /*
