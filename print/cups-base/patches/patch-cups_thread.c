$NetBSD: patch-cups_thread.c,v 1.2 2020/05/26 08:36:56 triaxx Exp $

Patch for macOS Sierra and before.

--- cups/thread.c.orig	2018-06-05 16:06:54.000000000 +0000
+++ cups/thread.c
@@ -14,6 +14,26 @@
 #include "cups-private.h"
 #include "thread-private.h"
 
+#if __APPLE__ && __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ < 101200
+#include <mach/mach_time.h>
+#ifndef CLOCK_REALTIME
+#define CLOCK_REALTIME 0
+#define CLOCK_MONOTONIC 0
+#endif
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
