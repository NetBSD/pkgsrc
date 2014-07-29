$NetBSD: patch-src_extension_internal_pdfinput_pdf-parser.cpp,v 1.3 2014/07/29 07:03:27 adam Exp $

Object.h is included in pdf-parser.h -- see patch for pdf-parser.h.

--- src/extension/internal/pdfinput/pdf-parser.cpp.orig	2012-12-13 17:00:46.000000000 +0000
+++ src/extension/internal/pdfinput/pdf-parser.cpp
@@ -38,7 +38,6 @@ extern "C" {
 #include "goo/GooHash.h"
 #include "GlobalParams.h"
 #include "CharTypes.h"
-#include "Object.h"
 #include "Array.h"
 #include "Dict.h"
 #include "Stream.h"
