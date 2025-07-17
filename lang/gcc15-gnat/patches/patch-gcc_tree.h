$NetBSD: patch-gcc_tree.h,v 1.1 2025/07/17 05:00:17 dkazankov Exp $

LTO compilation error

--- gcc/tree.h.orig	2025-04-25 08:18:04.000000000 +0000
+++ gcc/tree.h
@@ -1355,7 +1355,7 @@
 
 extern void protected_set_expr_location (tree, location_t);
 extern void protected_set_expr_location_if_unset (tree, location_t);
-ATTRIBUTE_WARN_UNUSED_RESULT
+WARN_UNUSED_RESULT
 extern tree protected_set_expr_location_unshare (tree, location_t);
 
 WARN_UNUSED_RESULT extern tree maybe_wrap_with_location (tree, location_t);
