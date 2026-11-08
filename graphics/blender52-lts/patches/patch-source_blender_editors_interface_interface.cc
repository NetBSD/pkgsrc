$NetBSD: patch-source_blender_editors_interface_interface.cc,v 1.1 2026/11/08 16:15:19 ryoon Exp $

--- source/blender/editors/interface/interface.cc.orig	2026-09-13 10:14:50.213140260 +0000
+++ source/blender/editors/interface/interface.cc
@@ -3695,7 +3695,7 @@ void button_range_set_soft(Button *but)
   }
   else if (but->poin && bool(but->pointype & BUT_POIN_TYPES)) {
     float value = button_value_get(but);
-    if (isfinite(value)) {
+    if (std::isfinite(value)) {
       CLAMP(value, but->hardmin, but->hardmax);
       but->softmin = min_ff(but->softmin, value);
       but->softmax = max_ff(but->softmax, value);
