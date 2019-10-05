$NetBSD: patch-pangox.c,v 1.1 2019/10/05 12:38:28 maya Exp $

Don't assign to a class that no longer exists in newer Pango.

--- pangox.c.orig	2012-08-27 23:19:32.000000000 +0000
+++ pangox.c
@@ -279,7 +279,7 @@ pango_x_font_class_init (PangoXFontClass
 
   font_class->describe = pango_x_font_describe;
   font_class->get_coverage = pango_x_font_get_coverage;
-  font_class->find_shaper = pango_x_font_find_shaper;
+  /*font_class->find_shaper = pango_x_font_find_shaper;*/
   font_class->get_glyph_extents = pango_x_font_get_glyph_extents;
   font_class->get_metrics = pango_x_font_get_metrics;
   font_class->get_font_map = pango_x_font_get_font_map;
