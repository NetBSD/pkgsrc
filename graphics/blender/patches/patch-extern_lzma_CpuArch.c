$NetBSD: patch-extern_lzma_CpuArch.c,v 1.1 2025/06/02 00:29:09 mrg Exp $

Copy of textproc/ugrep/patches/patch-lzma_C_CpuArch.c:

Fix build on non-Linux arm32/aarch64 platforms. Especially on NetBSD the
kernel currently only provides information about optional CPU features to
userland via /proc/cpuinfo. Providing AT_SUN_HWCAP via auxv would be
nice. Adding getauxval(3) to crt would also be nice.


--- extern/lzma/CpuArch.c.orig	2024-06-05 10:03:56.000000000 -0700
+++ extern/lzma/CpuArch.c	2025-05-31 18:49:25.342831722 -0700
@@ -760,12 +760,13 @@
 
 #else // __APPLE__
 
-#include <sys/auxv.h>
-
-#define USE_HWCAP
+#if defined(__linux__)
+#  define USE_HWCAP
+#endif
 
 #ifdef USE_HWCAP
 
+#include <sys/auxv.h>
 #include <asm/hwcap.h>
 
   #define MY_HWCAP_CHECK_FUNC_2(name1, name2) \
