$NetBSD: patch-src_extension_internal_pdfinput_pdf-parser.cpp,v 1.12 2019/11/23 09:23:22 martin Exp $

Object.h is included in pdf-parser.h -- see patch for pdf-parser.h.
Fix building with poppler 0.76.x.
Work around constness bugs (addChar should take a const arg).

--- src/extension/internal/pdfinput/pdf-parser.cpp.orig	2019-01-15 05:29:27.000000000 +0100
+++ src/extension/internal/pdfinput/pdf-parser.cpp	2019-11-23 10:14:30.693904450 +0100
@@ -41,7 +41,6 @@
 #include "goo/GooString.h"
 #include "GlobalParams.h"
 #include "CharTypes.h"
-#include "Object.h"
 #include "Array.h"
 #include "Dict.h"
 #include "Stream.h"
@@ -426,7 +425,7 @@
 	error(errInternal, -1, "Weird page contents");
     	return;
   }
-  parser = new Parser(xref, new Lexer(xref, obj), gFalse);
+  parser = new Parser(xref, obj, gFalse);
   go(topLevel);
   delete parser;
   parser = NULL;
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
