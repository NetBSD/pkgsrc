$NetBSD: patch-src_extension_internal_pdfinput_pdf-parser.h,v 1.5 2019/02/25 18:57:03 maya Exp $

Explicitly include poppler/Object.h; otherwise Python's Object.h gets included.
Support for poppler 0.72 from upstream by way of linuxfromscratch 

--- src/extension/internal/pdfinput/pdf-parser.h.orig	2018-03-11 20:38:09.000000000 +0000
+++ src/extension/internal/pdfinput/pdf-parser.h
@@ -9,6 +9,7 @@
 #define PDF_PARSER_H
 
 #ifdef HAVE_POPPLER
+#include "poppler-transition-api.h"
 
 #ifdef USE_GCC_PRAGMAS
 #pragma interface
@@ -25,8 +26,8 @@ namespace Inkscape {
 // TODO clean up and remove using:
 using Inkscape::Extension::Internal::SvgBuilder;
 
+#include "glib/poppler-features.h"
-#include "goo/gtypes.h"
-#include "Object.h"
+#include "poppler/Object.h"
 
 class GooString;
 class XRef;
@@ -127,11 +129,14 @@ public:
 
   // Constructor for regular output.
   PdfParser(XRef *xrefA, SvgBuilder *builderA, int pageNum, int rotate,
-            Dict *resDict, PDFRectangle *box, PDFRectangle *cropBox);
+            Dict *resDict,
+            _POPPLER_CONST PDFRectangle *box,
+            _POPPLER_CONST PDFRectangle *cropBox);
 
   // Constructor for a sub-page object.
   PdfParser(XRef *xrefA, Inkscape::Extension::Internal::SvgBuilder *builderA,
-            Dict *resDict, PDFRectangle *box);
+            Dict *resDict,
+            _POPPLER_CONST PDFRectangle *box);
 
   virtual ~PdfParser();
 
@@ -185,7 +190,7 @@ private:
 
   void go(GBool topLevel);
   void execOp(Object *cmd, Object args[], int numArgs);
-  PdfOperator *findOp(char *name);
+  PdfOperator *findOp(const char *name);
   GBool checkArg(Object *arg, TchkType type);
   int getPos();
 
@@ -256,7 +261,7 @@ private:
 			   double x2, double y2, GfxColor *color2,
 			   int nComps, int depth);
   void doPatchMeshShFill(GfxPatchMeshShading *shading);
-  void fillPatch(GfxPatch *patch, int nComps, int depth);
+  void fillPatch(_POPPLER_CONST GfxPatch *patch, int nComps, int depth);
   void doEndPath();
 
   // path clipping operators
@@ -287,7 +292,12 @@ private:
   void opMoveShowText(Object args[], int numArgs);
   void opMoveSetShowText(Object args[], int numArgs);
   void opShowSpaceText(Object args[], int numArgs);
+#if POPPLER_CHECK_VERSION(0,64,0)
+  void doShowText(const GooString *s);
+#else
   void doShowText(GooString *s);
+#endif
+  
 
   // XObject operators
   void opXObject(Object args[], int numArgs);
