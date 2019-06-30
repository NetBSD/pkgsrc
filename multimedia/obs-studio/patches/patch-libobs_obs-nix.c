$NetBSD: patch-libobs_obs-nix.c,v 1.1 2019/06/30 21:01:24 nia Exp $

Support NetBSD.

--- libobs/obs-nix.c.orig	2019-06-14 05:28:10.000000000 +0000
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
@@ -218,6 +220,7 @@ static void log_processor_info(void)
 
 static void log_memory_info(void)
 {
+#ifndef __NetBSD__
 	struct sysinfo info;
 	if (sysinfo(&info) < 0)
 		return;
@@ -226,6 +229,7 @@ static void log_memory_info(void)
 			(uint64_t)info.totalram * info.mem_unit / 1024 / 1024,
 			((uint64_t)info.freeram + (uint64_t)info.bufferram) *
 			info.mem_unit / 1024 / 1024);
+#endif
 }
 
 static void log_kernel_version(void)
