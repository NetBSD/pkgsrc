$NetBSD: patch-src_extension_internal_pdfinput_pdf-parser.cpp,v 1.23 2025/07/13 08:17:38 wiz Exp $

Fix build with poppler 25.7.0
https://gitlab.com/inkscape/inkscape/-/commit/ce52c5f96106ae5747171663a46831f21aa52d95

--- src/extension/internal/pdfinput/pdf-parser.cpp.orig	2025-07-12 23:26:27.013152690 +0000
+++ src/extension/internal/pdfinput/pdf-parser.cpp
@@ -27,6 +27,7 @@
 #include <cstdio>
 #include <cstdlib>
 #include <cstring>
+#include <memory>
 #include <mutex> // std::call_once()
 #include <utility>
 #include <vector>
@@ -686,7 +687,6 @@ void PdfParser::opSetLineWidth(Object ar
 void PdfParser::opSetExtGState(Object args[], int /*numArgs*/)
 {
     Object obj1, obj2, obj3, obj4, obj5;
-    Function *funcs[4] = {nullptr, nullptr, nullptr, nullptr};
     GfxColor backdropColor;
     GBool haveBackdropColor = gFalse;
     GBool alpha = gFalse;
@@ -744,13 +744,14 @@ void PdfParser::opSetExtGState(Object ar
         state->setLineWidth(obj2.getNum());
     }
 
+    _POPPLER_DECLARE_TRANSFER_FUNCTION_VECTOR(funcs);
+
     // transfer function
     if (_POPPLER_CALL_ARGS_DEREF(obj2, obj1.dictLookup, "TR2").isNull()) {
         _POPPLER_CALL_ARGS(obj2, obj1.dictLookup, "TR");
     }
     if (obj2.isName(const_cast<char *>("Default")) || obj2.isName(const_cast<char *>("Identity"))) {
-        funcs[0] = funcs[1] = funcs[2] = funcs[3] = nullptr;
-        state->setTransfer(funcs);
+        state->setTransfer(std::move(funcs));
     } else if (obj2.isArray() && obj2.arrayGetLength() == 4) {
         int pos = 4;
         for (int i = 0; i < 4; ++i) {
@@ -763,12 +764,14 @@ void PdfParser::opSetExtGState(Object ar
         }
         _POPPLER_FREE(obj3);
         if (pos == 4) {
-            state->setTransfer(funcs);
+            state->setTransfer(std::move(funcs));
         }
     } else if (obj2.isName() || obj2.isDict() || obj2.isStream()) {
         if ((funcs[0] = Function::parse(&obj2))) {
-            funcs[1] = funcs[2] = funcs[3] = nullptr;
-            state->setTransfer(funcs);
+            funcs[1] = nullptr;
+            funcs[2] = nullptr;
+            funcs[3] = nullptr;
+            state->setTransfer(std::move(funcs));
         }
     } else if (!obj2.isNull()) {
         error(errSyntaxError, getPos(), "Invalid transfer function in ExtGState");
@@ -790,8 +793,7 @@ void PdfParser::opSetExtGState(Object ar
                 funcs[0] = Function::parse(&obj3);
                 if (funcs[0]->getInputSize() != 1 || funcs[0]->getOutputSize() != 1) {
                     error(errSyntaxError, getPos(), "Invalid transfer function in soft mask in ExtGState");
-                    delete funcs[0];
-                    funcs[0] = nullptr;
+                    _POPPLER_DELETE_TRANSFER_FUNCTION(funcs[0]);
                 }
             }
             _POPPLER_FREE(obj3);
@@ -835,9 +837,10 @@ void PdfParser::opSetExtGState(Object ar
                             }
                         }
                     }
-                    doSoftMask(&obj3, alpha, blendingColorSpace.get(), isolated, knockout, funcs[0], &backdropColor);
+                    doSoftMask(&obj3, alpha, blendingColorSpace.get(), isolated, knockout,
+                               _POPPLER_GET_TRANSFER_FUNCTION_POINTER(funcs[0]), &backdropColor);
                     if (funcs[0]) {
-                        delete funcs[0];
+                        _POPPLER_DELETE_TRANSFER_FUNCTION(funcs[0]);
                     }
                 } else {
                     error(errSyntaxError, getPos(), "Invalid soft mask in ExtGState - missing group");
@@ -2312,11 +2315,11 @@ void PdfParser::doShowText(GooString *s)
         state->textTransformDelta(originX, originY, &tOriginX, &tOriginY);
 
         // In Gfx.cc this is drawChar(...)
-        builder->addChar(state, state->getCurX() + riseX, state->getCurY() + riseY,
+        builder->addChar(state, state->_POPPLER_GET_CUR_TEXT_X() + riseX, state->_POPPLER_GET_CUR_TEXT_Y() + riseY,
                          dx, dy, ax, ay, tOriginX, tOriginY, code, n, u, uLen);
 
         // Move onto next unicode character.
-        state->shift(tdx, tdy);
+        state->_POPPLER_TEXT_SHIFT_WITH_USER_COORDS(tdx, tdy);
         p += n;
         len -= n;
     }
