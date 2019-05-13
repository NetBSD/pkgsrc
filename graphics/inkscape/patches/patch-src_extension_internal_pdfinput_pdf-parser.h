$NetBSD: patch-src_extension_internal_pdfinput_pdf-parser.h,v 1.6 2019/05/13 16:17:51 adam Exp $

Explicitly include poppler/Object.h; otherwise Python's Object.h gets included.

--- src/extension/internal/pdfinput/pdf-parser.h.orig	2019-05-13 08:02:45.000000000 +0000
+++ src/extension/internal/pdfinput/pdf-parser.h
@@ -27,7 +27,7 @@ namespace Inkscape {
 using Inkscape::Extension::Internal::SvgBuilder;
 
 #include "glib/poppler-features.h"
-#include "Object.h"
+#include "poppler/Object.h"
 
 class GooString;
 class XRef;
