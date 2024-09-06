$NetBSD: patch-source_blender_editors_interface_interface.cc,v 1.2 2024/09/06 15:43:27 prlw1 Exp $

--- source/blender/editors/interface/interface.cc.orig	2024-06-05 11:47:57.000000000 +0000
+++ source/blender/editors/interface/interface.cc
@@ -3351,7 +3351,7 @@ void ui_but_range_set_soft(uiBut *but)
   }
   else if (but->poin && (but->pointype & UI_BUT_POIN_TYPES)) {
     float value = ui_but_value_get(but);
-    if (isfinite(value)) {
+    if (std::isfinite(value)) {
       CLAMP(value, but->hardmin, but->hardmax);
       but->softmin = min_ff(but->softmin, value);
       but->softmax = max_ff(but->softmax, value);
