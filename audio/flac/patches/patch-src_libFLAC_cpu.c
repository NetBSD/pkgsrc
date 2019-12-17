$NetBSD: patch-src_libFLAC_cpu.c,v 1.1 2019/12/17 13:59:50 nros Exp $

* check for getauxval and sys/auxv.h since it is not available on all systems

--- src/libFLAC/cpu.c.orig	2018-08-20 08:17:21.000000000 +0000
+++ src/libFLAC/cpu.c
@@ -53,7 +53,7 @@
 #define dfprintf(file, format, ...)
 #endif
 
-#if defined FLAC__CPU_PPC
+#if (defined(FLAC__CPU_PPC) && defined(HAVE_SYS_AUXV_H))
 #include <sys/auxv.h>
 #endif
 
@@ -236,7 +236,7 @@ x86_cpu_info (FLAC__CPUInfo *info)
 static void
 ppc_cpu_info (FLAC__CPUInfo *info)
 {
-#if defined FLAC__CPU_PPC
+#if (defined(FLAC__CPU_PPC) && defined(HAVE_GETAUXVAL))
 #ifndef PPC_FEATURE2_ARCH_3_00
 #define PPC_FEATURE2_ARCH_3_00		0x00800000
 #endif
