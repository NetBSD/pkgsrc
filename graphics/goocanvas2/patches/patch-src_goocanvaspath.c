$NetBSD: patch-src_goocanvaspath.c,v 1.1 2013/06/09 13:25:14 obache Exp $

* Fix some introspection generation warnings.
  https://git.gnome.org/browse/goocanvas/commit/?id=bfc08d9a34c5d3d598aa025dd514a11226dfe1be

--- src/goocanvaspath.c.orig	2011-10-01 15:07:18.000000000 +0000
+++ src/goocanvaspath.c
@@ -59,7 +59,7 @@ static void
 goo_canvas_path_install_common_properties (GObjectClass *gobject_class)
 {
   /**
-   * GooCanvasPath:data
+   * GooCanvasPath:data:
    *
    * The sequence of path commands, specified as a string using the same syntax
    * as in the <ulink url="http://www.w3.org/Graphics/SVG/">Scalable Vector
