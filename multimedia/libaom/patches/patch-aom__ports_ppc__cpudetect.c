$NetBSD: patch-aom__ports_ppc__cpudetect.c,v 1.4 2026/05/14 17:34:02 ryoon Exp $

Make this at least build on NetBSD.
So far no dynamic CPU feature detection on NetBSD.

--- aom_ports/ppc_cpudetect.c.orig	2026-04-01 20:41:46.000000000 +0000
+++ aom_ports/ppc_cpudetect.c
@@ -18,8 +18,10 @@
 #include "aom_ports/ppc.h"
 
 #if CONFIG_RUNTIME_CPU_DETECT
+#ifdef __linux
 #include <asm/cputable.h>
 #include <linux/auxvec.h>
+#endif
 
 static int cpu_env_flags(int *flags) {
   char *env;
