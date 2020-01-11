$NetBSD: patch-src_extension_internal_pdfinput_pdf-parser.cpp,v 1.13 2020/01/11 09:59:06 martin Exp $

Object.h is included in pdf-parser.h -- see patch for pdf-parser.h.
Fix building with poppler 0.76.x.
Work around constness bugs (addChar should take a const arg).
Add some needed const casts for GfxPath objects.

--- src/extension/internal/pdfinput/pdf-parser.cpp.orig	2020-01-11 10:11:43.316590715 +0100
+++ src/extension/internal/pdfinput/pdf-parser.cpp	2020-01-11 10:22:11.403079322 +0100
@@ -41,7 +41,6 @@
 #include "goo/GooString.h"
 #include "GlobalParams.h"
 #include "CharTypes.h"
-#include "Object.h"
 #include "Array.h"
 #include "Dict.h"
 #include "Stream.h"
@@ -342,7 +341,7 @@
         state->lineTo(cropBox->x1, cropBox->y2);
         state->closePath();
         state->clip();
-        clipHistory->setClip(state->getPath(), clipNormal);
+        clipHistory->setClip(const_cast<GfxPath*>(state->getPath()), clipNormal);
         builder->setClipPath(state);
         state->clearPath();
     }
@@ -426,7 +425,7 @@
 	error(errInternal, -1, "Weird page contents");
     	return;
   }
-  parser = new Parser(xref, new Lexer(xref, obj), gFalse);
+  parser = new Parser(xref, obj, gFalse);
   go(topLevel);
   delete parser;
   parser = NULL;
@@ -2143,10 +2142,10 @@
   if (state->isCurPt() && clip != clipNone) {
     state->clip();
     if (clip == clipNormal) {
-      clipHistory->setClip(state->getPath(), clipNormal);
+      clipHistory->setClip(const_cast<GfxPath*>(state->getPath()), clipNormal);
       builder->clip(state);
     } else {
-      clipHistory->setClip(state->getPath(), clipEO);
+      clipHistory->setClip(const_cast<GfxPath*>(state->getPath()), clipEO);
       builder->clip(state, true);
     }
   }
@@ -2414,7 +2413,7 @@
   int wMode;
   double riseX, riseY;
   CharCode code;
-  Unicode *u = NULL;
+  const Unicode *u = NULL;
   double x, y, dx, dy, tdx, tdy;
   double originX, originY, tOriginX, tOriginY;
   double oldCTM[6], newCTM[6];
@@ -2537,7 +2536,8 @@
       originY *= state->getFontSize();
       state->textTransformDelta(originX, originY, &tOriginX, &tOriginY);
       builder->addChar(state, state->getCurX() + riseX, state->getCurY() + riseY,
-                       dx, dy, tOriginX, tOriginY, code, n, u, uLen);
+                       dx, dy, tOriginX, tOriginY, code, n,
+		       const_cast<Unicode*>(u), uLen);
       state->shift(tdx, tdy);
       p += n;
       len -= n;
@@ -3112,7 +3112,7 @@
   state->lineTo(bbox[0], bbox[3]);
   state->closePath();
   state->clip();
-  clipHistory->setClip(state->getPath());
+  clipHistory->setClip(const_cast<GfxPath*>(state->getPath()));
   builder->clip(state);
   state->clearPath();
 
