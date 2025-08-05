$NetBSD: patch-src_init.c,v 1.1 2025/08/05 14:16:59 wiz Exp $

Add basic NetBSD support.
https://github.com/pytorch/cpuinfo/pull/315

--- src/init.c.orig	2025-07-24 17:36:24.000000000 +0000
+++ src/init.c
@@ -24,7 +24,7 @@ bool CPUINFO_ABI cpuinfo_initialize(void
 #if CPUINFO_ARCH_X86 || CPUINFO_ARCH_X86_64
 #if defined(__MACH__) && defined(__APPLE__)
 	pthread_once(&init_guard, &cpuinfo_x86_mach_init);
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__)
 	pthread_once(&init_guard, &cpuinfo_x86_freebsd_init);
 #elif defined(__linux__)
 	pthread_once(&init_guard, &cpuinfo_x86_linux_init);
