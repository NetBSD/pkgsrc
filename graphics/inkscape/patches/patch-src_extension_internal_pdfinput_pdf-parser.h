$NetBSD: patch-src_extension_internal_pdfinput_pdf-parser.h,v 1.1 2012/11/18 15:40:55 adam Exp $

Explicitly include poppler/Object.h; otherwise Python's Object.h gets included.

--- src/extension/internal/pdfinput/pdf-parser.h.orig	2012-11-18 14:42:04.000000000 +0000
+++ src/extension/internal/pdfinput/pdf-parser.h
@@ -27,7 +27,7 @@ namespace Inkscape {
 using Inkscape::Extension::Internal::SvgBuilder;
 
 #include "goo/gtypes.h"
-#include "Object.h"
+#include "poppler/Object.h"
 
 class GooString;
 class XRef;
