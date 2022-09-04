$NetBSD: patch-src_extension_internal_pdfinput_pdf-parser.cpp,v 1.19 2022/09/04 07:55:02 martin Exp $

Adapt to new poppler API

--- src/extension/internal/pdfinput/pdf-parser.cpp.orig	2022-05-07 15:43:15.000000000 +0200
+++ src/extension/internal/pdfinput/pdf-parser.cpp	2022-09-04 09:43:47.958399506 +0200
@@ -685,19 +685,18 @@ void PdfParser::opConcat(Object args[], 
 // TODO not good that numArgs is ignored but args[] is used:
 void PdfParser::opSetDash(Object args[], int /*numArgs*/)
 {
-  double *dash = nullptr;
+  std::vector<double> dash;
 
   Array *a = args[0].getArray();
   int length = a->getLength();
   if (length != 0) {
-    dash = (double *)gmallocn(length, sizeof(double));
     for (int i = 0; i < length; ++i) {
       Object obj;
-      dash[i] = _POPPLER_CALL_ARGS_DEREF(obj, a->get, i).getNum();
+      dash.push_back(_POPPLER_CALL_ARGS_DEREF(obj, a->get, i).getNum());
       _POPPLER_FREE(obj);
     }
   }
-  state->setLineDash(dash, length, args[1].getNum());
+  state->setLineDash(std::move(dash), args[1].getNum());
   builder->updateStyle(state);
 }
 
