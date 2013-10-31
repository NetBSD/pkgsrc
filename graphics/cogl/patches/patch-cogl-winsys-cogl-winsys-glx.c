$NetBSD: patch-cogl-winsys-cogl-winsys-glx.c,v 1.1 2013/10/31 21:28:07 hubertf Exp $

--- cogl/winsys/cogl-winsys-glx.c.orig	2013-02-21 15:41:08.000000000 +0000
+++ cogl/winsys/cogl-winsys-glx.c
@@ -58,6 +58,12 @@
 #include <fcntl.h>
 #include <time.h>
 
+/* HF: From http://stackoverflow.com/questions/5167269/clock-gettime-alternative-in-mac-os-x */
+#ifdef __MACH__
+#include <mach/clock.h>
+#include <mach/mach.h>
+#endif
+
 #include <glib/gi18n-lib.h>
 
 #include <GL/glx.h>
@@ -214,7 +220,20 @@ ensure_ust_type (CoglRenderer *renderer,
 
   /* This is the time source that the newer (fixed) linux drm
    * drivers use (Linux >= 3.8) */
-  clock_gettime (CLOCK_MONOTONIC, &ts);
+/* HF: From http://stackoverflow.com/questions/5167269/clock-gettime-alternative-in-mac-os-x */
+#ifdef __MACH__ // OS X does not have clock_gettime, use clock_get_time
+  {
+    clock_serv_t cclock;
+    mach_timespec_t mts;
+    host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &cclock);
+    clock_get_time(cclock, &mts);
+    mach_port_deallocate(mach_task_self(), cclock);
+    ts.tv_sec = mts.tv_sec;
+    ts.tv_nsec = mts.tv_nsec;
+  }
+#else
+  clock_gettime(CLOCK_REALTIME, &ts);
+#endif
   current_monotonic_time = (ts.tv_sec * G_GINT64_CONSTANT (1000000)) +
     (ts.tv_nsec / G_GINT64_CONSTANT (1000));
 
@@ -294,7 +313,20 @@ _cogl_winsys_get_clock_time (CoglContext
       {
         struct timespec ts;
 
-        clock_gettime (CLOCK_MONOTONIC, &ts);
+/* HF: From http://stackoverflow.com/questions/5167269/clock-gettime-alternative-in-mac-os-x */
+#ifdef __MACH__ // OS X does not have clock_gettime, use clock_get_time
+        {
+          clock_serv_t cclock;
+          mach_timespec_t mts;
+          host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &cclock);
+          clock_get_time(cclock, &mts);
+          mach_port_deallocate(mach_task_self(), cclock);
+          ts.tv_sec = mts.tv_sec;
+          ts.tv_nsec = mts.tv_nsec;
+        }
+#else
+        clock_gettime(CLOCK_REALTIME, &ts);
+#endif
         return ts.tv_sec * G_GINT64_CONSTANT (1000000000) + ts.tv_nsec;
       }
     }
@@ -1500,7 +1532,20 @@ _cogl_winsys_wait_for_vblank (CoglOnscre
                                           (current_count + 1) % 2,
                                           &current_count);
 
-          clock_gettime (CLOCK_MONOTONIC, &ts);
+/* HF: From http://stackoverflow.com/questions/5167269/clock-gettime-alternative-in-mac-os-x */
+#ifdef __MACH__ // OS X does not have clock_gettime, use clock_get_time
+          {
+            clock_serv_t cclock;
+            mach_timespec_t mts;
+            host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &cclock);
+            clock_get_time(cclock, &mts);
+            mach_port_deallocate(mach_task_self(), cclock);
+            ts.tv_sec = mts.tv_sec;
+            ts.tv_nsec = mts.tv_nsec;
+          }
+#else
+          clock_gettime(CLOCK_REALTIME, &ts);
+#endif
           info->presentation_time =
             ts.tv_sec * G_GINT64_CONSTANT (1000000000) + ts.tv_nsec;
         }
