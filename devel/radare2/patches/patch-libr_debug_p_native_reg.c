$NetBSD: patch-libr_debug_p_native_reg.c,v 1.1 2023/05/15 19:05:33 he Exp $

Use kfbsd-ppc.h on NetBSD/powerpc as well.

--- libr/debug/p/native/reg.c.orig	2023-01-23 10:53:42.000000000 +0000
+++ libr/debug/p/native/reg.c
@@ -27,6 +27,8 @@ static char *r_debug_native_reg_profile(
 #include "reg/netbsd-x86.h"
 #elif __x86_64__
 #include "reg/netbsd-x64.h"
+#elif __powerpc__
+#include "reg/kfbsd-ppc.h"
 #else
 #error "Unsupported BSD architecture"
 #endif
