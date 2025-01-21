$NetBSD: patch-third__party_cpuinfo_src_init.c,v 1.1 2025/01/21 13:36:49 ryoon Exp $

* Add NetBSD/i386 and amd64 support.

--- third_party/cpuinfo/src/init.c.orig	2025-01-20 07:07:43.416176101 +0000
+++ third_party/cpuinfo/src/init.c
@@ -30,6 +30,8 @@ bool CPUINFO_ABI cpuinfo_initialize(void
 	pthread_once(&init_guard, &cpuinfo_x86_linux_init);
 #elif defined(_WIN32) || defined(__CYGWIN__)
 	InitOnceExecuteOnce(&init_guard, &cpuinfo_x86_windows_init, NULL, NULL);
+#elif defined(__NetBSD__)
+	pthread_once(&init_guard, &cpuinfo_x86_netbsd_init);
 #else
 	cpuinfo_log_error("operating system is not supported in cpuinfo");
 #endif
