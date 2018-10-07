$NetBSD: patch-src_intel_vulkan_anv__device.c,v 1.1 2018/10/07 23:49:31 ryoon Exp $

* Without sysinfo() fall back to sysconf()
* Define ETIME if missing

FreeBSD Bugzilla - Bug 225415: graphics/mesa-dri: update to 18.0.0
https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=225415

--- src/intel/vulkan/anv_device.c.orig	2018-09-07 21:18:07.000000000 +0000
+++ src/intel/vulkan/anv_device.c
@@ -25,7 +25,9 @@
 #include <stdbool.h>
 #include <string.h>
 #include <sys/mman.h>
+#ifdef __GLIBC__
 #include <sys/sysinfo.h>
+#endif
 #include <unistd.h>
 #include <fcntl.h>
 #include <xf86drm.h>
@@ -42,6 +44,10 @@
 
 #include "genxml/gen7_pack.h"
 
+#ifndef ETIME
+#define ETIME ETIMEDOUT
+#endif
+
 static void
 compiler_debug_log(void *data, const char *fmt, ...)
 { }
@@ -61,11 +67,15 @@ compiler_perf_log(void *data, const char
 static VkResult
 anv_compute_heap_size(int fd, uint64_t gtt_size, uint64_t *heap_size)
 {
+#ifdef __GLIBC__
    /* Query the total ram from the system */
    struct sysinfo info;
    sysinfo(&info);
 
    uint64_t total_ram = (uint64_t)info.totalram * (uint64_t)info.mem_unit;
+#else
+   uint64_t total_ram = sysctlbyname(SYSCTL_MEMSIZE, &mem, &size, nullptr, 0);
+#endif
 
    /* We don't want to burn too much ram with the GPU.  If the user has 4GiB
     * or less, we use at most half.  If they have more than 4GiB, we use 3/4.
