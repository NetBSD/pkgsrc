$NetBSD: patch-src_goocanvasitemsimple.c,v 1.1 2013/06/09 13:25:14 obache Exp $

* Fix some introspection generation warnings.
  https://git.gnome.org/browse/goocanvas/commit/?id=bfc08d9a34c5d3d598aa025dd514a11226dfe1be

--- src/goocanvasitemsimple.c.orig	2011-10-09 18:14:23.000000000 +0000
+++ src/goocanvasitemsimple.c
@@ -273,7 +273,7 @@ goo_canvas_item_simple_install_common_pr
 						      G_PARAM_READWRITE));
 
   /**
-   * GooCanvasItemSimple:fill-color-gdk-rgba
+   * GooCanvasItemSimple:fill-color-gdk-rgba:
    *
    * The color to use to paint the interior of the item, specified as a GdkRGBA. To disable painting set the 'fill-pattern' property to NULL.
    *
@@ -322,7 +322,7 @@ goo_canvas_item_simple_install_common_pr
 				    "tooltip");
 
   /**
-   * GooCanvasItemSimple:clip-path
+   * GooCanvasItemSimple:clip-path:
    *
    * The sequence of commands describing the clip path of the item, specified
    * as a string using the same syntax
@@ -330,7 +330,7 @@ goo_canvas_item_simple_install_common_pr
    * Graphics (SVG)</ulink> path element.
    */
   /**
-   * GooCanvasItemModelSimple:clip-path
+   * GooCanvasItemModelSimple:clip-path:
    *
    * The sequence of commands describing the clip path of the item, specified
    * as a string using the same syntax
