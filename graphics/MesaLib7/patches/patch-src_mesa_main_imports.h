$NetBSD: patch-src_mesa_main_imports.h,v 1.1 2015/04/05 17:01:37 tnn Exp $

--- src/mesa/main/imports.h.orig	2011-10-15 00:43:58.000000000 +0000
+++ src/mesa/main/imports.h
@@ -570,7 +570,7 @@ _mesa_init_sqrt_table(void);
 #define _mesa_ffs(i)  ffs(i)
 #define _mesa_ffsll(i)  ffsll(i)
 
-#if ((_GNUC__ == 3 && __GNUC_MINOR__ >= 4) || __GNUC__ >= 4)
+#if ((__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || __GNUC__ >= 4)
 #define _mesa_bitcount(i) __builtin_popcount(i)
 #else
 extern unsigned int
