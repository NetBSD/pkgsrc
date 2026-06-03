$NetBSD: patch-third__party_fbgemm_external_cpuinfo_src_init.c,v 1.2 2026/06/03 06:45:40 wiz Exp $

Add NetBSD support.

--- third_party/fbgemm/external/cpuinfo/src/init.c.orig	2025-08-16 20:50:13.480312485 +0000
+++ third_party/fbgemm/external/cpuinfo/src/init.c
@@ -28,6 +28,8 @@ bool CPUINFO_ABI cpuinfo_initialize(void
 	pthread_once(&init_guard, &cpuinfo_x86_linux_init);
 #elif defined(_WIN32) || defined(__CYGWIN__)
 	InitOnceExecuteOnce(&init_guard, &cpuinfo_x86_windows_init, NULL, NULL);
+#elif defined(__NetBSD__)
+	pthread_once(&init_guard, &cpuinfo_x86_netbsd_init);
 #else
 	cpuinfo_log_error("operating system is not supported in cpuinfo");
 #endif
