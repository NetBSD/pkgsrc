$NetBSD: patch-src_goocanvasitem.h,v 1.1 2013/06/09 13:25:14 obache Exp $

* Fix some introspection generation warnings.
  https://git.gnome.org/browse/goocanvas/commit/?id=bfc08d9a34c5d3d598aa025dd514a11226dfe1be

--- src/goocanvasitem.h.orig	2011-10-01 11:41:10.000000000 +0000
+++ src/goocanvasitem.h
@@ -65,7 +65,7 @@ typedef struct _GooCanvasItemModel  GooC
 
 
 /**
- * GooCanvasItem
+ * GooCanvasItem:
  *
  * #GooCanvasItem is a typedef used for objects that implement the
  * #GooCanvasItem interface.
@@ -77,7 +77,7 @@ typedef struct _GooCanvasItem       GooC
 
 
 /**
- * GooCanvasItemIface
+ * GooCanvasItemIface:
  * @get_canvas: returns the canvas the item is in.
  * @set_canvas: sets the canvas the item is in.
  * @get_n_children: returns the number of children of the item.
