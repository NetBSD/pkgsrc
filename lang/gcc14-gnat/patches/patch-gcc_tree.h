$NetBSD: patch-gcc_tree.h,v 1.1 2025/04/25 19:35:10 dkazankov Exp $

LTO compilation error

--- gcc/tree.h.orig	2024-05-07 09:51:41.000000000 +0300
+++ gcc/tree.h	2024-07-19
@@ -1340,7 +1340,7 @@
 
 extern void protected_set_expr_location (tree, location_t);
 extern void protected_set_expr_location_if_unset (tree, location_t);
-ATTRIBUTE_WARN_UNUSED_RESULT
+WARN_UNUSED_RESULT
 extern tree protected_set_expr_location_unshare (tree, location_t);
 
 WARN_UNUSED_RESULT extern tree maybe_wrap_with_location (tree, location_t);
