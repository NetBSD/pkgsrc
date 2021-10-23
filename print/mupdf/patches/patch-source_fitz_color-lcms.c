$NetBSD: patch-source_fitz_color-lcms.c,v 1.1 2021/10/23 15:22:07 leot Exp $

memset(3) needs string.h.

--- source/fitz/color-lcms.c.orig	2021-10-05 10:44:43.000000000 +0000
+++ source/fitz/color-lcms.c
@@ -22,6 +22,8 @@
 
 #include "mupdf/fitz.h"
 
+#include <string.h>
+
 #include "color-imp.h"
 
 #if FZ_ENABLE_ICC
