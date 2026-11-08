$NetBSD: patch-source_blender_editors_util_numinput.cc,v 1.1 2026/11/08 16:15:19 ryoon Exp $

--- source/blender/editors/util/numinput.cc.orig	2026-06-03 13:03:49.000000000 +0000
+++ source/blender/editors/util/numinput.cc
@@ -74,7 +74,7 @@ bool ED_numinput_double_is_int(double value)
 {
   value = std::abs(value);
   /* Use `>=` because `uint64_t::max` rounds up to 2^64 when converted to double. */
-  if (!isfinite(value) || value >= double(std::numeric_limits<uint64_t>::max())) {
+  if (!std::isfinite(value) || value >= double(std::numeric_limits<uint64_t>::max())) {
     return false;
   }
   return value == double(uint64_t(value));
@@ -666,7 +666,7 @@ bool handleNumInput(bContext *C, NumInput *n, const wm
     }
 #endif
 
-    if (UNLIKELY(!isfinite(n->val[idx]))) {
+    if (UNLIKELY(!std::isfinite(n->val[idx]))) {
       n->val[idx] = val_prev;
       n->val_flag[idx] |= NUM_INVALID;
     }
