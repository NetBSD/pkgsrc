$NetBSD: patch-src_extension_internal_pdfinput_pdf-parser.cpp,v 1.5 2015/02/03 13:55:12 adam Exp $

Object.h is included in pdf-parser.h -- see patch for pdf-parser.h.

--- src/extension/internal/pdfinput/pdf-parser.cpp.orig	2014-06-09 13:24:41.000000000 +0000
+++ src/extension/internal/pdfinput/pdf-parser.cpp
@@ -38,7 +38,7 @@ extern "C" {
 #include "goo/GooHash.h"
 #include "GlobalParams.h"
 #include "CharTypes.h"
-#include "Object.h"
+#define POPPLER_EVEN_NEWER_NEW_COLOR_SPACE_API 1
 #include "Array.h"
 #include "Dict.h"
 #include "Stream.h"
