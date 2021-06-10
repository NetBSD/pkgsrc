$NetBSD: patch-lib_CL_pocl__timing.c,v 1.2 2021/06/10 12:26:26 nia Exp $

NetBSD does not have CLOCK_UPTIME_FAST.
https://github.com/pocl/pocl/pull/949

--- lib/CL/pocl_timing.c.orig	2021-05-19 08:12:19.000000000 +0000
+++ lib/CL/pocl_timing.c
@@ -74,7 +74,7 @@ uint64_t pocl_gettimemono_ns() {
 #   warning Using clock_gettime with CLOCK_MONOTONIC for monotonic clocks
   clock_gettime(CLOCK_MONOTONIC, &timespec);
 #  endif
-# elif defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__FreeBSD_kernel__)
+# elif defined(__DragonFly__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
   clock_gettime(CLOCK_UPTIME_FAST, &timespec);
 # else
 # warning Using clock_gettime with CLOCK_REALTIME for monotonic clocks
