$NetBSD: patch-src_hotspot_os_bsd_os__perf__bsd.cpp,v 1.1 2019/10/01 12:36:34 tnn Exp $

sys/user.h was removed from NetBSD.
KERN_PROC_PATHNAME is available from NetBSD>=7.99.23

--- src/hotspot/os/bsd/os_perf_bsd.cpp.orig	2019-09-19 12:22:38.000000000 +0000
+++ src/hotspot/os/bsd/os_perf_bsd.cpp
@@ -34,7 +34,9 @@
   #include <mach/mach.h>
   #include <mach/task_info.h>
 #else
+#ifndef __NetBSD__
   #include <sys/user.h>
+#endif
   #include <sys/sched.h>
   #include <sys/resource.h>
   #define NET_RT_IFLIST2 NET_RT_IFLIST
@@ -857,6 +859,9 @@ int SystemProcessInterface::SystemProces
 
   for (int i = 0; i < pid_count; i++) {
     // Executable path
+#if !defined(KERN_PROC_PATHNAME)
+#define KERN_PROC_PATHNAME 5
+#endif
     int pmib[] = { CTL_KERN, KERN_PROC_ARGS, lproc[i].p_pid, KERN_PROC_PATHNAME };
     const u_int pmiblen = sizeof(pmib) / sizeof(pmib[0]);
     char pbuf[PATH_MAX];
