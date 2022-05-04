$NetBSD: patch-src_extension_internal_pdfinput_pdf-parser.cpp,v 1.17 2022/05/04 21:13:52 wiz Exp $

Fix build with poppler-22.4.0
https://gitlab.com/inkscape/inkscape/-/issues/3387

--- src/extension/internal/pdfinput/pdf-parser.cpp.orig	2022-02-05 01:12:19.000000000 +0000
+++ src/extension/internal/pdfinput/pdf-parser.cpp
@@ -30,6 +30,7 @@
 #include "Gfx.h"
 #include "pdf-parser.h"
 #include "util/units.h"
+#include "poppler-transition-api.h"
 
 #include "glib/poppler-features.h"
 #include "goo/gmem.h"
@@ -2158,7 +2159,7 @@ void PdfParser::opSetCharSpacing(Object 
 // TODO not good that numArgs is ignored but args[] is used:
 void PdfParser::opSetFont(Object args[], int /*numArgs*/)
 {
-  GfxFont *font = res->lookupFont(args[0].getName());
+  auto font = res->lookupFont(args[0].getName());
 
   if (!font) {
     // unsetting the font (drawing no text) is better than using the
@@ -2179,7 +2180,9 @@ void PdfParser::opSetFont(Object args[],
     fflush(stdout);
   }
 
+#if !POPPLER_CHECK_VERSION(22, 4, 0)
   font->incRefCnt();
+#endif
   state->setFont(font, args[1].getNum());
   fontChanged = gTrue;
 }
@@ -2373,7 +2376,6 @@ void PdfParser::doShowText(const GooStri
 #else
 void PdfParser::doShowText(GooString *s) {
 #endif
-  GfxFont *font;
   int wMode;
   double riseX, riseY;
   CharCode code;
@@ -2392,7 +2394,7 @@ void PdfParser::doShowText(GooString *s)
 #endif
   int len, n, uLen;
 
-  font = state->getFont();
+  auto font = state->getFont();
   wMode = font->getWMode();
 
   builder->beginString(state);
@@ -2445,10 +2447,10 @@ void PdfParser::doShowText(GooString *s)
       //out->updateCTM(state, 1, 0, 0, 1, 0, 0);
       if (false){ /*!out->beginType3Char(state, curX + riseX, curY + riseY, tdx, tdy,
 			       code, u, uLen)) {*/
-        _POPPLER_CALL_ARGS(charProc, ((Gfx8BitFont *)font)->getCharProc, code);
-	if ((resDict = ((Gfx8BitFont *)font)->getResources())) {
+        _POPPLER_CALL_ARGS(charProc, _POPPLER_FONTPTR_TO_GFX8(font)->getCharProc, code);
+    if (resDict = _POPPLER_FONTPTR_TO_GFX8(font)->getResources()) {
 	  pushResources(resDict);
-	}
+    }
 	if (charProc.isStream()) {
 	  //parse(&charProc, gFalse); // TODO: parse into SVG font
 	} else {
