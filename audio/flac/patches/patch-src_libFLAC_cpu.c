$NetBSD: patch-src_libFLAC_cpu.c,v 1.2 2022/02/21 08:19:41 adam Exp $

Check for getauxval and sys/auxv.h since it is not available on all systems

--- src/libFLAC/cpu.c.orig	2021-07-09 20:24:42.000000000 +0000
+++ src/libFLAC/cpu.c
@@ -53,7 +53,7 @@
 #define dfprintf(file, format, ...)
 #endif
 
-#if defined FLAC__CPU_PPC
+#if (defined(FLAC__CPU_PPC) && defined(HAVE_SYS_AUXV_H))
 #if defined(__linux__) || (defined(__FreeBSD__) && (__FreeBSD__ >= 12))
 #include <sys/auxv.h>
 #endif
@@ -238,7 +238,7 @@ x86_cpu_info (FLAC__CPUInfo *info)
 static void
 ppc_cpu_info (FLAC__CPUInfo *info)
 {
-#if defined FLAC__CPU_PPC
+#if (defined(FLAC__CPU_PPC) && defined(HAVE_GETAUXVAL))
 #ifndef PPC_FEATURE2_ARCH_3_00
 #define PPC_FEATURE2_ARCH_3_00		0x00800000
 #endif
