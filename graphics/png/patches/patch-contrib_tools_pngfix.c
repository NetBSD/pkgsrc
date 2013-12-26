$NetBSD: patch-contrib_tools_pngfix.c,v 1.1 2013/12/26 15:59:20 tron Exp $

Fix build with C compilers other than GCC.

--- contrib/tools/pngfix.c.orig	2013-11-14 19:03:02.000000000 +0000
+++ contrib/tools/pngfix.c	2013-12-26 15:44:27.000000000 +0000
@@ -32,7 +32,6 @@
 #  define FIX_GCC volatile
 #else
 #  define FIX_GCC
-#  error not tested
 #endif
 
 #define PROGRAM_NAME "pngfix"
