$NetBSD: patch-subvertpy_wc.c,v 1.1 2011/11/24 22:32:01 cheusov Exp $

# PR 45649
--- subvertpy/wc.c.orig	2011-10-26 00:23:01.000000000 +0000
+++ subvertpy/wc.c
@@ -27,6 +27,7 @@
 
 #include "util.h"
 #include "editor.h"
+#include "wc.h"
 
 #ifndef T_BOOL
 #define T_BOOL T_BYTE
