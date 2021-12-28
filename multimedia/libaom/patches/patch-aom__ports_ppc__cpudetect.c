$NetBSD: patch-aom__ports_ppc__cpudetect.c,v 1.2 2021/12/28 17:35:52 gutteridge Exp $

Make this at least build on NetBSD.
So far no dynamic CPU feature detection on NetBSD.

--- aom_ports/ppc_cpudetect.c.orig	2021-10-14 18:05:43.000000000 +0000
+++ aom_ports/ppc_cpudetect.c
@@ -12,14 +12,16 @@
 #include <fcntl.h>
 #include <unistd.h>
 #include <stdint.h>
+#if !defined(__NetBSD__)
 #include <asm/cputable.h>
 #include <linux/auxvec.h>
+#endif
 
 #include "config/aom_config.h"
 
 #include "aom_ports/ppc.h"
 
-#if CONFIG_RUNTIME_CPU_DETECT
+#if (CONFIG_RUNTIME_CPU_DETECT && !defined(__NetBSD__))
 static int cpu_env_flags(int *flags) {
   char *env;
   env = getenv("AOM_SIMD_CAPS");
