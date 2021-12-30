$NetBSD: patch-src_text.c,v 1.1 2021/12/30 00:26:21 nia Exp $

string.h needed for strlen().

--- src/text.c.orig	1997-12-10 23:27:49.000000000 +0000
+++ src/text.c
@@ -6,6 +6,8 @@
 */
 
 #include <X11/Xlib.h>
+#include <stdlib.h>
+#include <string.h>
 #include "text.h"
 
 int FontHeight(XFontStruct *font_struct)
