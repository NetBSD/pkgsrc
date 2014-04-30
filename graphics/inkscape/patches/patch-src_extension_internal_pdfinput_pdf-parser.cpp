$NetBSD: patch-src_extension_internal_pdfinput_pdf-parser.cpp,v 1.2 2014/04/30 06:15:20 wiz Exp $

Object.h is included in pdf-parser.h -- see patch for pdf-parser.h.

Fix build with poppler-0.26.0.

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
@@ -861,7 +860,7 @@ void PdfParser::opSetExtGState(Object ar
 	  isolated = knockout = gFalse;
 	  if (!obj4.dictLookup(const_cast<char*>("CS"), &obj5)->isNull()) {
 #if defined(POPPLER_NEW_COLOR_SPACE_API) || defined(POPPLER_NEW_ERRORAPI)
-	    blendingColorSpace = GfxColorSpace::parse(&obj5, NULL);
+	    blendingColorSpace = GfxColorSpace::parse(&obj5, NULL, state);
 #else
 	    blendingColorSpace = GfxColorSpace::parse(&obj5);
 #endif
@@ -1085,9 +1084,9 @@ void PdfParser::opSetFillColorSpace(Obje
   res->lookupColorSpace(args[0].getName(), &obj);
 #if defined(POPPLER_NEW_COLOR_SPACE_API) || defined(POPPLER_NEW_ERRORAPI)
   if (obj.isNull()) {
-    colorSpace = GfxColorSpace::parse(&args[0], NULL);
+    colorSpace = GfxColorSpace::parse(&args[0], NULL, state);
   } else {
-    colorSpace = GfxColorSpace::parse(&obj, NULL);
+    colorSpace = GfxColorSpace::parse(&obj, NULL, state);
   }
 #else
   if (obj.isNull()) {
@@ -1120,9 +1119,9 @@ void PdfParser::opSetStrokeColorSpace(Ob
   res->lookupColorSpace(args[0].getName(), &obj);
 #if defined(POPPLER_NEW_COLOR_SPACE_API) || defined(POPPLER_NEW_ERRORAPI)
   if (obj.isNull()) {
-    colorSpace = GfxColorSpace::parse(&args[0], NULL);
+    colorSpace = GfxColorSpace::parse(&args[0], NULL, state);
   } else {
-    colorSpace = GfxColorSpace::parse(&obj, NULL);
+    colorSpace = GfxColorSpace::parse(&obj, NULL, state);
   }
 #else
   if (obj.isNull()) {
@@ -1213,7 +1212,7 @@ void PdfParser::opSetFillColorN(Object a
     }
 #if defined(POPPLER_NEW_COLOR_SPACE_API) || defined(POPPLER_NEW_ERRORAPI)
     if (args[numArgs-1].isName() &&
-	(pattern = res->lookupPattern(args[numArgs-1].getName(), NULL))) {
+	(pattern = res->lookupPattern(args[numArgs-1].getName(), NULL, state))) {
       state->setFillPattern(pattern);
       builder->updateStyle(state);
     }
@@ -1273,7 +1272,7 @@ void PdfParser::opSetStrokeColorN(Object
     }
 #if defined(POPPLER_NEW_COLOR_SPACE_API) || defined(POPPLER_NEW_ERRORAPI)
     if (args[numArgs-1].isName() &&
-	(pattern = res->lookupPattern(args[numArgs-1].getName(), NULL))) {
+	(pattern = res->lookupPattern(args[numArgs-1].getName(), NULL, state))) {
       state->setStrokePattern(pattern);
       builder->updateStyle(state);
     }
@@ -1711,7 +1710,7 @@ void PdfParser::opShFill(Object args[], 
   GBool savedState = gFalse;
 
 #if defined(POPPLER_NEW_COLOR_SPACE_API) || defined(POPPLER_NEW_ERRORAPI)
-  if (!(shading = res->lookupShading(args[0].getName(), NULL))) {
+  if (!(shading = res->lookupShading(args[0].getName(), NULL, state))) {
     return;
   }
 #else
@@ -2727,7 +2726,7 @@ void PdfParser::doImage(Object *ref, Str
     }
     if (!obj1.isNull()) {
 #if defined(POPPLER_NEW_COLOR_SPACE_API) || defined(POPPLER_NEW_ERRORAPI)
-      colorSpace = GfxColorSpace::parse(&obj1, NULL);
+      colorSpace = GfxColorSpace::parse(&obj1, NULL, state);
 #else
       colorSpace = GfxColorSpace::parse(&obj1);
 #endif
@@ -2816,7 +2815,7 @@ void PdfParser::doImage(Object *ref, Str
 	}
       }
 #if defined(POPPLER_NEW_COLOR_SPACE_API) || defined(POPPLER_NEW_ERRORAPI)
-      maskColorSpace = GfxColorSpace::parse(&obj1, NULL);
+      maskColorSpace = GfxColorSpace::parse(&obj1, NULL, state);
 #else
       maskColorSpace = GfxColorSpace::parse(&obj1);
 #endif
@@ -3007,7 +3006,7 @@ void PdfParser::doForm(Object *str) {
       transpGroup = gTrue;
       if (!obj1.dictLookup(const_cast<char*>("CS"), &obj3)->isNull()) {
 #if defined(POPPLER_NEW_COLOR_SPACE_API) || defined(POPPLER_NEW_ERRORAPI)
-	blendingColorSpace = GfxColorSpace::parse(&obj3, NULL);
+	blendingColorSpace = GfxColorSpace::parse(&obj3, NULL, state);
 #else
 	blendingColorSpace = GfxColorSpace::parse(&obj3);
 #endif
