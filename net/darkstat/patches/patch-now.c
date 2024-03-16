$NetBSD: patch-now.c,v 1.1 2024/03/16 22:36:01 nia Exp $

Remove the internal copy of clock_gettime for OS X and use the version
from macports-legacy-support since libpcap requires it anyway.

--- now.c.orig	2024-03-16 22:31:55.000000000 +0000
+++ now.c
@@ -23,43 +23,6 @@
 #include <string.h>
 #include <time.h>
 
-#if defined(__MACH__) && !defined(__gnu_hurd__)
-/* Fake up clock_gettime() on OS X. */
-#  include <sys/time.h>
-#  include <inttypes.h>
-#  include <mach/mach.h>
-#  include <mach/mach_time.h>
-
-   typedef int clockid_t;
-#  define CLOCK_REALTIME 0
-#  define CLOCK_MONOTONIC 1
-
-   static uint64_t mono_first = 0;
-
-   int clock_gettime(clockid_t clk_id, struct timespec *tp) {
-      if (clk_id == CLOCK_REALTIME) {
-         struct timeval tv;
-         gettimeofday(&tv, NULL);
-         tp->tv_sec = tv.tv_sec;
-         tp->tv_nsec = tv.tv_usec * 1000;
-         return 0;
-      }
-      if (clk_id == CLOCK_MONOTONIC) {
-         uint64_t t = mach_absolute_time();
-         mach_timebase_info_data_t timebase;
-         mach_timebase_info(&timebase);
-         if (!mono_first) {
-            mono_first = t;
-         }
-         uint64_t tdiff = (t - mono_first) * timebase.numer / timebase.denom;
-         tp->tv_sec = tdiff / 1000000000;
-         tp->tv_nsec = tdiff % 1000000000;
-         return 0;
-      }
-      return -1;
-   }
-#endif  /* __MACH__ */
-
 static struct timespec clock_real, clock_mono;
 static int now_initialized = 0;
 
