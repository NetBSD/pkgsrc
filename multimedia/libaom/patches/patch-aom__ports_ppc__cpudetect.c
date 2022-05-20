$NetBSD: patch-aom__ports_ppc__cpudetect.c,v 1.2.4.1 2022/05/20 13:05:56 bsiegert Exp $

Make this at least build on NetBSD.
So far no dynamic CPU feature detection on NetBSD.

--- aom_ports/ppc_cpudetect.c.orig	2022-02-15 07:20:42.000000000 +0000
+++ aom_ports/ppc_cpudetect.c
@@ -12,14 +12,16 @@
 #include <fcntl.h>
 #include <unistd.h>
 #include <stdint.h>
+#ifdef __linux
 #include <asm/cputable.h>
 #include <linux/auxvec.h>
+#endif
 
 #include "config/aom_config.h"
 
 #include "aom_ports/ppc.h"
 
-#if CONFIG_RUNTIME_CPU_DETECT
+#if (CONFIG_RUNTIME_CPU_DETECT && defined(__linux))
 static int cpu_env_flags(int *flags) {
   char *env;
   env = getenv("AOM_SIMD_CAPS");
