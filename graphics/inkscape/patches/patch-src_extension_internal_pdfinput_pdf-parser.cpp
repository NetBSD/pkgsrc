$NetBSD: patch-src_extension_internal_pdfinput_pdf-parser.cpp,v 1.11 2019/05/13 16:17:51 adam Exp $

Object.h is included in pdf-parser.h -- see patch for pdf-parser.h.
Fix building with poppler 0.76.x.

--- src/extension/internal/pdfinput/pdf-parser.cpp.orig	2019-01-15 04:29:27.000000000 +0000
+++ src/extension/internal/pdfinput/pdf-parser.cpp
@@ -41,7 +41,6 @@ extern "C" {
 #include "goo/GooString.h"
 #include "GlobalParams.h"
 #include "CharTypes.h"
-#include "Object.h"
 #include "Array.h"
 #include "Dict.h"
 #include "Stream.h"
@@ -426,7 +425,7 @@ void PdfParser::parse(Object *obj, GBool
 	error(errInternal, -1, "Weird page contents");
     	return;
   }
-  parser = new Parser(xref, new Lexer(xref, obj), gFalse);
+  parser = new Parser(xref, obj, gFalse);
   go(topLevel);
   delete parser;
   parser = NULL;
