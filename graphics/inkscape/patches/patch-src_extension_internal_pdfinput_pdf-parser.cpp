$NetBSD: patch-src_extension_internal_pdfinput_pdf-parser.cpp,v 1.1 2012/12/30 10:31:14 adam Exp $

Object.h is included in pdf-parser.h -- see patch for pdf-parser.h.

--- src/extension/internal/pdfinput/pdf-parser.cpp.orig	2012-12-30 09:44:48.000000000 +0000
+++ src/extension/internal/pdfinput/pdf-parser.cpp
@@ -38,7 +38,6 @@ extern "C" {
 #include "goo/GooHash.h"
 #include "GlobalParams.h"
 #include "CharTypes.h"
-#include "Object.h"
 #include "Array.h"
 #include "Dict.h"
 #include "Stream.h"
