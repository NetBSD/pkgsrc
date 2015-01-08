$NetBSD: patch-src_extension_internal_pdfinput_pdf-parser.cpp,v 1.4 2015/01/08 16:34:29 wiz Exp $

Object.h is included in pdf-parser.h -- see patch for pdf-parser.h.

Fix build with poppler-0.29+ based on https://bugs.launchpad.net/inkscape/+bug/1399811

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
@@ -860,7 +859,9 @@ void PdfParser::opSetExtGState(Object ar
 	  blendingColorSpace = NULL;
 	  isolated = knockout = gFalse;
 	  if (!obj4.dictLookup(const_cast<char*>("CS"), &obj5)->isNull()) {
-#if defined(POPPLER_EVEN_NEWER_COLOR_SPACE_API)
+#if defined(POPPLER_EVEN_NEWER_NEW_COLOR_SPACE_API)
+	    blendingColorSpace = GfxColorSpace::parse(NULL, &obj5, NULL, NULL);
+#elif defined(POPPLER_EVEN_NEWER_COLOR_SPACE_API)
 	    blendingColorSpace = GfxColorSpace::parse(&obj5, NULL, NULL);
 #elif defined(POPPLER_NEW_COLOR_SPACE_API) || defined(POPPLER_NEW_ERRORAPI)
 	    blendingColorSpace = GfxColorSpace::parse(&obj5, NULL);
@@ -1085,7 +1086,13 @@ void PdfParser::opSetFillColorSpace(Obje
 
   state->setFillPattern(NULL);
   res->lookupColorSpace(args[0].getName(), &obj);
-#if defined(POPPLER_EVEN_NEWER_COLOR_SPACE_API)
+#if defined(POPPLER_EVEN_NEWER_NEW_COLOR_SPACE_API)
+  if (obj.isNull()) {
+    colorSpace = GfxColorSpace::parse(NULL, &args[0], NULL, NULL);
+  } else {
+    colorSpace = GfxColorSpace::parse(NULL, &obj, NULL, NULL);
+  }
+#elif defined(POPPLER_EVEN_NEWER_COLOR_SPACE_API)
   if (obj.isNull()) {
     colorSpace = GfxColorSpace::parse(&args[0], NULL, NULL);
   } else {
@@ -1126,7 +1133,13 @@ void PdfParser::opSetStrokeColorSpace(Ob
 
   state->setStrokePattern(NULL);
   res->lookupColorSpace(args[0].getName(), &obj);
-#if defined(POPPLER_EVEN_NEWER_COLOR_SPACE_API)
+#if defined(POPPLER_EVEN_NEWER_NEW_COLOR_SPACE_API)
+  if (obj.isNull()) {
+    colorSpace = GfxColorSpace::parse(NULL, &args[0], NULL, NULL);
+  } else {
+    colorSpace = GfxColorSpace::parse(NULL, &obj, NULL, NULL);
+  }
+#elif defined(POPPLER_EVEN_NEWER_COLOR_SPACE_API)
   if (obj.isNull()) {
     colorSpace = GfxColorSpace::parse(&args[0], NULL, NULL);
   } else {
@@ -2756,8 +2769,10 @@ void PdfParser::doImage(Object *ref, Str
       }
     }
     if (!obj1.isNull()) {
-#if defined(POPPLER_EVEN_NEWER_COLOR_SPACE_API)
-            colorSpace = GfxColorSpace::parse(&obj1, NULL, NULL);
+#if defined(POPPLER_EVEN_NEWER_NEW_COLOR_SPACE_API)
+      colorSpace = GfxColorSpace::parse(NULL, &obj1, NULL, NULL);
+#elif defined(POPPLER_EVEN_NEWER_COLOR_SPACE_API)
+      colorSpace = GfxColorSpace::parse(&obj1, NULL, NULL);
 #elif defined(POPPLER_NEW_COLOR_SPACE_API) || defined(POPPLER_NEW_ERRORAPI)
       colorSpace = GfxColorSpace::parse(&obj1, NULL);
 #else
@@ -2847,8 +2862,10 @@ void PdfParser::doImage(Object *ref, Str
 	  obj2.free();
 	}
       }
-#if defined(POPPLER_EVEN_NEWER_COLOR_SPACE_API)
-            GfxColorSpace *maskColorSpace = GfxColorSpace::parse(&obj1, NULL, NULL);
+#if defined(POPPLER_EVEN_NEWER_NEW_COLOR_SPACE_API)
+      GfxColorSpace *maskColorSpace = GfxColorSpace::parse(NULL, &obj1, NULL, NULL);
+#elif defined(POPPLER_EVEN_NEWER_COLOR_SPACE_API)
+      GfxColorSpace *maskColorSpace = GfxColorSpace::parse(&obj1, NULL, NULL);
 #elif defined(POPPLER_NEW_COLOR_SPACE_API) || defined(POPPLER_NEW_ERRORAPI)
       maskColorSpace = GfxColorSpace::parse(&obj1, NULL);
 #else
@@ -3040,7 +3057,9 @@ void PdfParser::doForm(Object *str) {
     if (obj1.dictLookup(const_cast<char*>("S"), &obj2)->isName(const_cast<char*>("Transparency"))) {
       transpGroup = gTrue;
       if (!obj1.dictLookup(const_cast<char*>("CS"), &obj3)->isNull()) {
-#if defined(POPPLER_EVEN_NEWER_COLOR_SPACE_API)
+#if defined(POPPLER_EVEN_NEWER_NEW_COLOR_SPACE_API)
+	blendingColorSpace = GfxColorSpace::parse(NULL, &obj3, NULL, NULL);
+#elif defined(POPPLER_EVEN_NEWER_COLOR_SPACE_API)
 	blendingColorSpace = GfxColorSpace::parse(&obj3, NULL, NULL);
 #elif defined(POPPLER_NEW_COLOR_SPACE_API) || defined(POPPLER_NEW_ERRORAPI)
 	blendingColorSpace = GfxColorSpace::parse(&obj3, NULL);
