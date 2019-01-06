$NetBSD: patch-src_extension_internal_pdfinput_pdf-parser.cpp,v 1.10 2019/01/06 08:41:01 markd Exp $

- Object.h is included in pdf-parser.h -- see patch for pdf-parser.h.
- Support for poppler 0.72 from upstream by way of linuxfromscratch 

--- src/extension/internal/pdfinput/pdf-parser.cpp.orig	2018-03-11 20:38:09.000000000 +0000
+++ src/extension/internal/pdfinput/pdf-parser.cpp
@@ -36,12 +36,11 @@ extern "C" {
 #include "pdf-parser.h"
 #include "util/units.h"
 
+#include "glib/poppler-features.h"
 #include "goo/gmem.h"
-#include "goo/GooTimer.h"
-#include "goo/GooHash.h"
+#include "goo/GooString.h"
 #include "GlobalParams.h"
 #include "CharTypes.h"
-#include "Object.h"
 #include "Array.h"
 #include "Dict.h"
 #include "Stream.h"
@@ -295,8 +294,8 @@ PdfParser::PdfParser(XRef *xrefA,
                      int /*pageNum*/,
 		     int rotate,
 		     Dict *resDict,
-                     PDFRectangle *box,
-		     PDFRectangle *cropBox) :
+                     _POPPLER_CONST PDFRectangle *box,
+                     _POPPLER_CONST PDFRectangle *cropBox) :
     xref(xrefA),
     builder(builderA),
     subPage(gFalse),
@@ -318,7 +317,7 @@ PdfParser::PdfParser(XRef *xrefA,
   builder->setDocumentSize(Inkscape::Util::Quantity::convert(state->getPageWidth(), "pt", "px"),
                            Inkscape::Util::Quantity::convert(state->getPageHeight(), "pt", "px"));
 
-  double *ctm = state->getCTM();
+  const double *ctm = state->getCTM();
   double scaledCTM[6];
   for (int i = 0; i < 6; ++i) {
     baseMatrix[i] = ctm[i];
@@ -353,7 +352,7 @@ PdfParser::PdfParser(XRef *xrefA,
 PdfParser::PdfParser(XRef *xrefA,
 		     Inkscape::Extension::Internal::SvgBuilder *builderA,
                      Dict *resDict,
-		     PDFRectangle *box) :
+		     _POPPLER_CONST PDFRectangle *box) :
     xref(xrefA),
     builder(builderA),
     subPage(gTrue),
@@ -572,7 +571,7 @@ const char *PdfParser::getPreviousOperat
 
 void PdfParser::execOp(Object *cmd, Object args[], int numArgs) {
   PdfOperator *op;
-  char *name;
+  const char *name;
   Object *argPtr;
   int i;
 
@@ -620,7 +619,7 @@ void PdfParser::execOp(Object *cmd, Obje
   (this->*op->func)(argPtr, numArgs);
 }
 
-PdfOperator* PdfParser::findOp(char *name) {
+PdfOperator* PdfParser::findOp(const char *name) {
   int a = -1;
   int b = numOps;
   int cmp = -1;
@@ -1752,7 +1751,7 @@ void PdfParser::doShadingPatternFillFall
                                              GBool stroke, GBool eoFill) {
   GfxShading *shading;
   GfxPath *savedPath;
-  double *ctm, *btm, *ptm;
+  const double *ctm, *btm, *ptm;
   double m[6], ictm[6], m1[6];
   double xMin, yMin, xMax, yMax;
   double det;
@@ -1994,7 +1993,7 @@ void PdfParser::doFunctionShFill1(GfxFun
   GfxColor color0M, color1M, colorM0, colorM1, colorMM;
   GfxColor colors2[4];
   double functionColorDelta = colorDeltas[pdfFunctionShading-1];
-  double *matrix;
+  const double *matrix;
   double xM, yM;
   int nComps, i, j;
 
@@ -2174,7 +2173,7 @@ void PdfParser::doPatchMeshShFill(GfxPat
   }
 }
 
-void PdfParser::fillPatch(GfxPatch *patch, int nComps, int depth) {
+void PdfParser::fillPatch(_POPPLER_CONST GfxPatch *patch, int nComps, int depth) {
   GfxPatch patch00 = blankPatch();
   GfxPatch patch01 = blankPatch();
   GfxPatch patch10 = blankPatch();
@@ -2582,7 +2581,11 @@ void PdfParser::opShowSpaceText(Object a
   }
 }
 
+#if POPPLER_CHECK_VERSION(0,64,0)
+void PdfParser::doShowText(const GooString *s) {
+#else
 void PdfParser::doShowText(GooString *s) {
+#endif
   GfxFont *font;
   int wMode;
   double riseX, riseY;
@@ -2591,17 +2594,21 @@ void PdfParser::doShowText(GooString *s)
   double x, y, dx, dy, tdx, tdy;
   double originX, originY, tOriginX, tOriginY;
   double oldCTM[6], newCTM[6];
-  double *mat;
+  const double *mat;
   Object charProc;
   Dict *resDict;
   Parser *oldParser;
+#if POPPLER_CHECK_VERSION(0,64,0)
+  const char *p;
+#else
   char *p;
+#endif
   int len, n, uLen;
 
   font = state->getFont();
   wMode = font->getWMode();
 
-  builder->beginString(state, s);
+  builder->beginString(state);
 
   // handle a Type 3 char
   if (font->getType() == fontType3 && 0) {//out->interpretType3Chars()) {
@@ -2732,7 +2739,11 @@ void PdfParser::opXObject(Object args[],
 {
   Object obj1, obj2, obj3, refObj;
 
+#if POPPLER_CHECK_VERSION(0,64,0)
+  const char *name = args[0].getName();
+#else
   char *name = args[0].getName();
+#endif
 #if defined(POPPLER_NEW_OBJECT_API)
   if ((obj1 = res->lookupXObject(name)).isNull()) {
 #else
@@ -3657,7 +3668,6 @@ void PdfParser::opBeginImage(Object /*ar
 Stream *PdfParser::buildImageStream() {
   Object dict;
   Object obj;
-  char *key;
   Stream *str;
 
   // build dictionary
@@ -3675,26 +3685,17 @@ Stream *PdfParser::buildImageStream() {
       obj.free();
 #endif
     } else {
-      key = copyString(obj.getName());
-#if defined(POPPLER_NEW_OBJECT_API)
-      obj = parser->getObj();
-#else
-      obj.free();
-      parser->getObj(&obj);
-#endif
-      if (obj.isEOF() || obj.isError()) {
-	gfree(key);
+      Object obj2;
+      _POPPLER_CALL(obj2, parser->getObj);
+      if (obj2.isEOF() || obj2.isError()) {
+        _POPPLER_FREE(obj);
 	break;
       }
-#if defined(POPPLER_NEW_OBJECT_API)
-      dict.dictAdd(key, std::move(obj));
-    }
-    obj = parser->getObj();
-#else
-      dict.dictAdd(key, &obj);
+      _POPPLER_DICTADD(dict, obj.getName(), obj2);
+      _POPPLER_FREE(obj);
+      _POPPLER_FREE(obj2);
     }
-    parser->getObj(&obj);
-#endif
+    _POPPLER_CALL(obj, parser->getObj);
   }
   if (obj.isEOF()) {
     error(errSyntaxError, getPos(), "End of file in inline image");
