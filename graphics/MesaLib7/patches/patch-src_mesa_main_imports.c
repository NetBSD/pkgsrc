$NetBSD: patch-src_mesa_main_imports.c,v 1.1 2015/04/05 17:01:37 tnn Exp $

--- src/mesa/main/imports.c.orig	2011-10-15 00:43:58.000000000 +0000
+++ src/mesa/main/imports.c
@@ -514,7 +514,7 @@ _mesa_ffsll(int64_t val)
 #endif
 
 #if !defined(__GNUC__) ||\
-   ((_GNUC__ == 3 && __GNUC_MINOR__ < 4) && __GNUC__ < 4)
+   ((__GNUC__ == 3 && __GNUC_MINOR__ < 4) && __GNUC__ < 4)
 /**
  * Return number of bits set in given GLuint.
  */
