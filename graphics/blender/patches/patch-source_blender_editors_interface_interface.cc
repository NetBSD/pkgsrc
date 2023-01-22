$NetBSD: patch-source_blender_editors_interface_interface.cc,v 1.1 2023/01/22 21:24:37 ryoon Exp $

--- source/blender/editors/interface/interface.cc.orig	2022-11-04 00:33:07.000000000 +0000
+++ source/blender/editors/interface/interface.cc
@@ -3370,7 +3370,7 @@ void ui_but_range_set_soft(uiBut *but)
   }
   else if (but->poin && (but->pointype & UI_BUT_POIN_TYPES)) {
     float value = ui_but_value_get(but);
-    if (isfinite(value)) {
+    if (std::isfinite(value)) {
       CLAMP(value, but->hardmin, but->hardmax);
       but->softmin = min_ff(but->softmin, value);
       but->softmax = max_ff(but->softmax, value);
