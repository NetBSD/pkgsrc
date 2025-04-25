$NetBSD: patch-gcc_config_arm_elf.h,v 1.1 2025/04/25 19:35:10 dkazankov Exp $

FIXME: description

--- gcc/config/arm/elf.h.orig	2024-05-07 09:51:37.000000000 +0300
+++ gcc/config/arm/elf.h
@@ -157,6 +157,8 @@
 #undef L_floatdidf
 #undef L_floatdisf
 #undef L_floatundidf
+/* XXXMRG: don't take this out, we need it! */
+# ifndef __NetBSD__
 #undef L_floatundisf
+# endif
 #endif
-
