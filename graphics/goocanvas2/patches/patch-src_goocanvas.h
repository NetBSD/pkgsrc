$NetBSD: patch-src_goocanvas.h,v 1.1 2013/06/09 13:25:14 obache Exp $

* Fix some introspection generation warnings.
  https://git.gnome.org/browse/goocanvas/commit/?id=bfc08d9a34c5d3d598aa025dd514a11226dfe1be

--- src/goocanvas.h.orig	2011-10-01 11:41:10.000000000 +0000
+++ src/goocanvas.h
@@ -34,7 +34,7 @@ G_BEGIN_DECLS
 typedef struct _GooCanvasClass  GooCanvasClass;
 
 /**
- * GooCanvas
+ * GooCanvas:
  *
  * The #GooCanvas-struct struct contains private data only.
  */
@@ -162,7 +162,7 @@ struct _GooCanvas
 };
 
 /**
- * GooCanvasClass
+ * GooCanvasClass:
  * @create_item: a virtual method that subclasses may override to create custom
  *  canvas items for item models.
  * @item_created: signal emitted when a new canvas item has been created.
