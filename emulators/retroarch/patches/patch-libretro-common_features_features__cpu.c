$NetBSD: patch-libretro-common_features_features__cpu.c,v 1.1 2019/05/20 12:42:40 nia Exp $

Use clock_gettime on BSD.

--- libretro-common/features/features_cpu.c.orig	2019-05-08 06:06:23.000000000 +0000
+++ libretro-common/features/features_cpu.c
@@ -26,6 +26,7 @@
 #if defined(_WIN32)
 #include <direct.h>
 #else
+#define _POSIX_C_SOURCE 200112
 #include <unistd.h>
 #endif
 
@@ -167,7 +168,7 @@ retro_perf_tick_t cpu_features_get_perf_
    tv_sec     = (long)((ularge.QuadPart - epoch) / 10000000L);
    tv_usec    = (long)(system_time.wMilliseconds * 1000);
    time_ticks = (1000000 * tv_sec + tv_usec);
-#elif defined(__linux__) || defined(__QNX__) || defined(__MACH__)
+#elif defined(__linux__) || defined(BSD) || defined(__QNX__) || defined(__MACH__)
    struct timespec tv = {0};
    if (ra_clock_gettime(CLOCK_MONOTONIC, &tv) == 0)
       time_ticks = (retro_perf_tick_t)tv.tv_sec * 1000000000 +
