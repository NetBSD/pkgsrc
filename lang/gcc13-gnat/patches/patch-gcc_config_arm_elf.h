$NetBSD: patch-gcc_config_arm_elf.h,v 1.3 2025/10/15 20:04:57 dkazankov Exp $

FIXME

--- gcc/config/arm/elf.h.orig	2021-04-08 04:56:28.065740630 -0700
+++ gcc/config/arm/elf.h
@@ -147,6 +147,8 @@
 #undef L_floatdidf
 #undef L_floatdisf
 #undef L_floatundidf
+/* XXXMRG: don't take this out, we need it! */
+# ifndef __NetBSD__
 #undef L_floatundisf
+# endif
 #endif
-
