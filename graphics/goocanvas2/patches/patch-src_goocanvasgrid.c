$NetBSD: patch-src_goocanvasgrid.c,v 1.1 2013/06/09 13:25:14 obache Exp $

* Fix some introspection generation warnings.
  https://git.gnome.org/browse/goocanvas/commit/?id=bfc08d9a34c5d3d598aa025dd514a11226dfe1be

--- src/goocanvasgrid.c.orig	2011-10-03 13:03:33.000000000 +0000
+++ src/goocanvasgrid.c
@@ -247,7 +247,7 @@ goo_canvas_grid_install_common_propertie
 						      G_PARAM_READWRITE));
 
   /**
-   * GooCanvasGrid:horz-grid-line-color-gdk-rgba
+   * GooCanvasGrid:horz-grid-line-color-gdk-rgba:
    *
    * The color to use for the horizontal grid lines, specified as a GdkRGBA.
    *
@@ -282,7 +282,7 @@ goo_canvas_grid_install_common_propertie
 						      G_PARAM_READWRITE));
 
   /**
-   * GooCanvasGrid:vert-grid-line-color-gdk-rgba
+   * GooCanvasGrid:vert-grid-line-color-gdk-rgba:
    *
    * The color to use for the vertical grid lines, specified as a GdkRGBA.
    *
@@ -317,7 +317,7 @@ goo_canvas_grid_install_common_propertie
 						      G_PARAM_READWRITE));
 
   /**
-   * GooCanvasGrid:border-color-gdk-rgba
+   * GooCanvasGrid:border-color-gdk-rgba:
    *
    * The color to use for the border, specified as a GdkRGBA.
    *
