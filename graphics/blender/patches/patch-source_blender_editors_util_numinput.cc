$NetBSD: patch-source_blender_editors_util_numinput.cc,v 1.1 2024/09/06 15:43:27 prlw1 Exp $

--- source/blender/editors/util/numinput.cc.orig	2024-06-05 11:47:57.000000000 +0000
+++ source/blender/editors/util/numinput.cc
@@ -620,7 +620,7 @@ bool handleNumInput(bContext *C, NumInpu
     }
 #endif
 
-    if (UNLIKELY(!isfinite(n->val[idx]))) {
+    if (UNLIKELY(!std::isfinite(n->val[idx]))) {
       n->val[idx] = val_prev;
       n->val_flag[idx] |= NUM_INVALID;
     }
