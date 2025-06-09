$NetBSD: patch-gcc-objc-objc-act.c,v 1.1 2025/06/09 16:00:48 js Exp $

Make all ObjC methods saveds.

--- gcc/objc/objc-act.c.orig	2025-05-31 23:13:39.128573359 +0200
+++ gcc/objc/objc-act.c	2025-05-31 23:13:44.450437107 +0200
@@ -5215,6 +5215,13 @@
   else
     ftype = build_function_type_vec (return_type, argtypes);
 
+#ifdef TARGET_BASEREL
+  if (TARGET_BASEREL)
+    TYPE_ATTRIBUTES (ftype) = tree_cons (get_identifier ("saveds"),
+					 NULL_TREE,
+					 TYPE_ATTRIBUTES (ftype));
+#endif
+
   release_tree_vector (argtypes);
   return ftype;
 }
