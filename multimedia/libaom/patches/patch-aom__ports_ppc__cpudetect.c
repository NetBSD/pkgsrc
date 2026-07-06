$NetBSD: patch-aom__ports_ppc__cpudetect.c,v 1.5 2026/07/06 21:46:26 he Exp $

Make this at least build on NetBSD.
So far no dynamic CPU feature detection on NetBSD.

--- aom_ports/ppc_cpudetect.c.orig	2026-04-01 20:41:46.000000000 +0000
+++ aom_ports/ppc_cpudetect.c
@@ -17,9 +17,11 @@
 
 #include "aom_ports/ppc.h"
 
-#if CONFIG_RUNTIME_CPU_DETECT
+#if CONFIG_RUNTIME_CPU_DETECT && !defined(__NetBSD__)
+#ifdef __linux
 #include <asm/cputable.h>
 #include <linux/auxvec.h>
+#endif
 
 static int cpu_env_flags(int *flags) {
   char *env;
