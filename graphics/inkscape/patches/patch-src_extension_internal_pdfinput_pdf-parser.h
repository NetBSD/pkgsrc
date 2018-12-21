$NetBSD: patch-src_extension_internal_pdfinput_pdf-parser.h,v 1.3 2018/12/21 08:46:16 wiz Exp $

Explicitly include poppler/Object.h; otherwise Python's Object.h gets included.

--- src/extension/internal/pdfinput/pdf-parser.h.orig	2017-08-06 20:44:00.000000000 +0000
+++ src/extension/internal/pdfinput/pdf-parser.h
@@ -25,8 +25,18 @@ namespace Inkscape {
 // TODO clean up and remove using:
 using Inkscape::Extension::Internal::SvgBuilder;
 
-#include "goo/gtypes.h"
-#include "Object.h"
+#include "poppler/Object.h"
+
+// poppler 0.72
+#define getCString c_str
+
+// poppler 0.71
+typedef bool GBool;
+#define gTrue true
+#define gFalse false  
+
+// poppler 0.70
+#define _POPPLER_CONST const
 
 class GooString;
 class XRef;
