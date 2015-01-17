$NetBSD: patch-cogl-winsys-cogl-winsys-glx.c,v 1.4 2015/01/17 14:28:51 prlw1 Exp $

* for Mac OS X, missing clock_gettime(2), taken from MacPorts.
  https://bugzilla.gnome.org/show_bug.cgi?id=741647

--- cogl/winsys/cogl-winsys-glx.c.orig	2013-07-09 15:20:23.000000000 +0000
+++ cogl/winsys/cogl-winsys-glx.c
@@ -58,7 +58,26 @@
 #include <sys/stat.h>
 #include <sys/time.h>
 #include <fcntl.h>
+
+#ifdef __MACH__
+#include <mach/mach_time.h>
+#define CLOCK_REALTIME 0
+#define CLOCK_MONOTONIC 0
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
+#else
 #include <time.h>
+#endif
 
 #include <GL/glx.h>
 #include <X11/Xlib.h>
