$NetBSD: patch-libobs_obs-nix.c,v 1.2 2019/10/03 20:33:15 nia Exp $

Support NetBSD.

--- libobs/obs-nix.c.orig	2019-09-20 15:14:16.000000000 +0000
+++ libobs/obs-nix.c
@@ -26,7 +26,9 @@
 #if defined(__FreeBSD__)
 #include <sys/sysctl.h>
 #endif
+#ifndef __NetBSD__
 #include <sys/sysinfo.h>
+#endif
 #include <sys/utsname.h>
 #include <xcb/xcb.h>
 #if USE_XINPUT
@@ -216,6 +218,7 @@ static void log_processor_info(void)
 
 static void log_memory_info(void)
 {
+#ifndef __NetBSD__
 	struct sysinfo info;
 	if (sysinfo(&info) < 0)
 		return;
@@ -225,6 +228,7 @@ static void log_memory_info(void)
 	     (uint64_t)info.totalram * info.mem_unit / 1024 / 1024,
 	     ((uint64_t)info.freeram + (uint64_t)info.bufferram) *
 		     info.mem_unit / 1024 / 1024);
+#endif
 }
 
 static void log_kernel_version(void)
