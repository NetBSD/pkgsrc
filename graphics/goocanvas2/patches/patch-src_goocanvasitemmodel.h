$NetBSD: patch-src_goocanvasitemmodel.h,v 1.1 2013/06/09 13:25:14 obache Exp $

* Fix some introspection generation warnings.
  https://git.gnome.org/browse/goocanvas/commit/?id=bfc08d9a34c5d3d598aa025dd514a11226dfe1be

--- src/goocanvasitemmodel.h.orig	2010-06-30 20:31:13.000000000 +0000
+++ src/goocanvasitemmodel.h
@@ -20,7 +20,7 @@ G_BEGIN_DECLS
 
 
 /**
- * GooCanvasItemModel
+ * GooCanvasItemModel:
  *
  * #GooCanvasItemModel is a typedef used for objects that implement the
  * #GooCanvasItemModel interface.
@@ -33,7 +33,7 @@ G_BEGIN_DECLS
 
 
 /**
- * GooCanvasItemModelIface
+ * GooCanvasItemModelIface:
  * @get_n_children: returns the number of children of the model.
  * @get_child: returns the child at the given index.
  * @add_child: adds a child.
