$NetBSD: patch-gcc_config_aarch64_aarch64-netbsd.h,v 1.1 2022/06/16 15:43:55 adam Exp $

Match what is in NetBSD src.  Fixes at least aarch64eb, and
probably several others.

--- gcc/config/aarch64/aarch64-netbsd.h.orig	2021-04-08 04:56:28.033740243 -0700
+++ gcc/config/aarch64/aarch64-netbsd.h	2021-04-24 00:16:41.451665444 -0700
@@ -20,6 +20,10 @@
 #ifndef GCC_AARCH64_NETBSD_H
 #define GCC_AARCH64_NETBSD_H
 
+/* NetBSD malloc(3) does 64, not 128 bytes. */
+#undef MALLOC_ABI_ALIGNMENT
+#define MALLOC_ABI_ALIGNMENT  64
+
 #define TARGET_LINKER_BIG_EMULATION "aarch64nbsdb"
 #define TARGET_LINKER_LITTLE_EMULATION "aarch64nbsd"
 
