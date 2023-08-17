$NetBSD: patch-third__party_cpuinfo_src_init.c,v 1.1 2023/08/17 07:43:40 jperkin Exp $

Support SunOS.

--- third_party/cpuinfo/src/init.c.orig	2023-04-26 22:11:56.000000000 +0000
+++ third_party/cpuinfo/src/init.c
@@ -29,7 +29,7 @@ bool CPUINFO_ABI cpuinfo_initialize(void
         pthread_once(&init_guard, &cpuinfo_x86_linux_init);
     #elif defined(_WIN32) || defined(__CYGWIN__)
         InitOnceExecuteOnce(&init_guard, &cpuinfo_x86_windows_init, NULL, NULL);
-    #elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__) || defined(__DragonFly__)
+    #elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__) || defined(__DragonFly__) || defined(__sun)
         pthread_once(&init_guard, &cpuinfo_x86_bsd_init);
     #else
         cpuinfo_log_error("operating system is not supported in cpuinfo");
