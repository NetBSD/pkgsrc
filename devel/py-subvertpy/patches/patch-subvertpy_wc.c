$NetBSD: patch-subvertpy_wc.c,v 1.2 2011/11/25 09:46:02 cheusov Exp $

# PR 45649, https://bugs.launchpad.net/subvertpy/+bug/894659
--- subvertpy/wc.c.orig	2011-10-26 00:23:01.000000000 +0000
+++ subvertpy/wc.c
@@ -27,6 +27,7 @@
 
 #include "util.h"
 #include "editor.h"
+#include "wc.h"
 
 #ifndef T_BOOL
 #define T_BOOL T_BYTE
