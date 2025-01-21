$NetBSD: patch-third__party_fbgemm_third__party_cpuinfo_src_init.c,v 1.1 2025/01/21 13:36:49 ryoon Exp $

* Add NetBSD/i386 and amd64 support.

--- third_party/fbgemm/third_party/cpuinfo/src/init.c.orig	2025-01-20 07:10:28.351796926 +0000
+++ third_party/fbgemm/third_party/cpuinfo/src/init.c
@@ -27,6 +27,8 @@ bool CPUINFO_ABI cpuinfo_initialize(void
 		pthread_once(&init_guard, &cpuinfo_x86_mach_init);
 	#elif defined(__linux__)
 		pthread_once(&init_guard, &cpuinfo_x86_linux_init);
+	#elif defined(__NetBSD__)
+		pthread_once(&init_guard, &cpuinfo_x86_netbsd_init);
 	#elif defined(_WIN32) || defined(__CYGWIN__)
 		InitOnceExecuteOnce(&init_guard, &cpuinfo_x86_windows_init, NULL, NULL);
 	#else
