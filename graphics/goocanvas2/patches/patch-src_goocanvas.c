$NetBSD: patch-src_goocanvas.c,v 1.1 2013/06/09 13:25:14 obache Exp $

* Fix some introspection generation warnings.
  https://git.gnome.org/browse/goocanvas/commit/?id=bfc08d9a34c5d3d598aa025dd514a11226dfe1be

--- src/goocanvas.c.orig	2011-10-09 17:38:11.000000000 +0000
+++ src/goocanvas.c
@@ -420,7 +420,7 @@ goo_canvas_class_init (GooCanvasClass *k
 						      G_PARAM_WRITABLE));
 
   /**
-   * GooCanvas:background-color-gdk-rgba
+   * GooCanvas:background-color-gdk-rgba:
    *
    * The color to use for the canvas background, specified as a GdkRGBA.
    *
@@ -463,7 +463,7 @@ goo_canvas_class_init (GooCanvasClass *k
   /* Signals. */
 
   /**
-   * GooCanvas::item-created
+   * GooCanvas::item-created:
    * @canvas: the canvas.
    * @item: the new item.
    * @model: the item's model.
