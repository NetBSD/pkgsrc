$NetBSD: patch-src_goocanvasitemsimple.h,v 1.1 2013/06/09 13:25:14 obache Exp $

* Fix some introspection generation warnings.
  https://git.gnome.org/browse/goocanvas/commit/?id=bfc08d9a34c5d3d598aa025dd514a11226dfe1be

--- src/goocanvasitemsimple.h.orig	2010-06-30 20:31:13.000000000 +0000
+++ src/goocanvasitemsimple.h
@@ -17,7 +17,7 @@ G_BEGIN_DECLS
 
 
 /**
- * GooCanvasItemSimpleData
+ * GooCanvasItemSimpleData:
  * @style: the style to draw with.
  * @transform: the transformation matrix of the item, or %NULL.
  * @clip_path_commands: an array of #GooCanvasPathCommand specifying the clip
@@ -76,7 +76,7 @@ typedef struct _GooCanvasItemSimpleClass
 typedef struct _GooCanvasItemModelSimple       GooCanvasItemModelSimple;
 
 /**
- * GooCanvasItemSimple
+ * GooCanvasItemSimple:
  * @canvas: the canvas.
  * @parent: the parent item.
  * @model: the item's model, if it has one.
@@ -111,7 +111,7 @@ struct _GooCanvasItemSimple
 };
 
 /**
- * GooCanvasItemSimpleClass
+ * GooCanvasItemSimpleClass:
  * @simple_create_path: simple subclasses that draw basic shapes and paths only
  *  need to override this one method. It creates the path for the item.
  *  All updating, painting and hit-testing is provided automatically by the
@@ -202,7 +202,7 @@ void	 goo_canvas_item_simple_set_model		
 typedef struct _GooCanvasItemModelSimpleClass  GooCanvasItemModelSimpleClass;
 
 /**
- * GooCanvasItemModelSimple
+ * GooCanvasItemModelSimple:
  * @parent: the parent model.
  * @simple_data: data used by the canvas item for viewing the model.
  *
