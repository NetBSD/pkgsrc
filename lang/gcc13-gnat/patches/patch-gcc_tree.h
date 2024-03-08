$NetBSD: patch-gcc_tree.h,v 1.1 2024/03/08 12:02:34 wiz Exp $

LTO compilation error

--- gcc/tree.h.orig	2023-07-27 11:13:07.000000000 +0300
+++ gcc/tree.h	2023-12-08 12:16:52.159026794 +0200
@@ -1299,7 +1299,7 @@
 
 extern void protected_set_expr_location (tree, location_t);
 extern void protected_set_expr_location_if_unset (tree, location_t);
-ATTRIBUTE_WARN_UNUSED_RESULT
+WARN_UNUSED_RESULT
 extern tree protected_set_expr_location_unshare (tree, location_t);
 
 WARN_UNUSED_RESULT extern tree maybe_wrap_with_location (tree, location_t);
