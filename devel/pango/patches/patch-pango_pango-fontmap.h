$NetBSD: patch-pango_pango-fontmap.h,v 1.1 2012/12/19 03:02:50 obache Exp $

* Drop last use of deprecated G_CONST_RETURN
  http://git.gnome.org/browse/pango/commit/?id=13bc45cdc7de772cde80dc4d5f58fef251229e1b

--- pango/pango-fontmap.h.orig	2012-12-06 15:36:19.000000000 +0000
+++ pango/pango-fontmap.h
@@ -89,7 +89,7 @@ struct _PangoFontMapClass
   void (*_pango_reserved3) (void);
 };
 
-G_CONST_RETURN char   *pango_font_map_get_shape_engine_type (PangoFontMap *fontmap);
+const char   *pango_font_map_get_shape_engine_type (PangoFontMap *fontmap);
 
 #endif /* PANGO_ENABLE_BACKEND */
 
