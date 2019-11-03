$NetBSD: patch-src_hotspot_os_bsd_os__perf__bsd.cpp,v 1.2 2019/11/03 00:37:28 tnn Exp $

KERN_PROC_PATHNAME is available from NetBSD>=7.99.23

--- src/hotspot/os/bsd/os_perf_bsd.cpp.orig	2019-10-16 18:31:09.000000000 +0000
+++ src/hotspot/os/bsd/os_perf_bsd.cpp
@@ -859,6 +859,9 @@ int SystemProcessInterface::SystemProces
 
   for (int i = 0; i < pid_count; i++) {
     // Executable path
+#if !defined(KERN_PROC_PATHNAME)
+#define KERN_PROC_PATHNAME 5
+#endif
     int pmib[] = { CTL_KERN, KERN_PROC_ARGS, lproc[i].p_pid, KERN_PROC_PATHNAME };
     const u_int pmiblen = sizeof(pmib) / sizeof(pmib[0]);
     char pbuf[PATH_MAX];
