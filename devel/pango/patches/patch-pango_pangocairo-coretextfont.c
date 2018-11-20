$NetBSD: patch-pango_pangocairo-coretextfont.c,v 1.1 2018/11/20 08:34:43 maya Exp $

From 60df2b006e5d4553abc7bb5fe9a99539c91b0022 Mon Sep 17 00:00:00 2001
From: Tom Schoonjans <Tom.Schoonjans%diamond.ac.uk@localhost>
Date: Fri, 20 Jul 2018 12:30:34 +0100
Subject: [PATCH] Revert "Restore scaling of CoreText fonts."

This reverts commit f661cdbf8cfbdb2ba7241d8dfa4a579c6dfe0a94.

--- pango/pangocairo-coretextfont.c.orig	2018-07-16 00:50:43.000000000 +0000
+++ pango/pangocairo-coretextfont.c
@@ -36,7 +36,6 @@ struct _PangoCairoCoreTextFont
 {
   PangoCoreTextFont font;
   PangoCairoFontPrivate cf_priv;
-  int abs_size;
 };
 
 struct _PangoCairoCoreTextFontClass
@@ -163,17 +162,6 @@ pango_cairo_core_text_font_create_base_m
   return metrics;
 }
 
-static PangoFontDescription *
-pango_cairo_core_text_font_describe_absolute (PangoFont *font)
-{
-  PangoCairoCoreTextFont *cafont = (PangoCairoCoreTextFont *)font;
-  PangoFontDescription *desc = pango_font_describe (font);
-  
-  pango_font_description_set_absolute_size (desc, cafont->abs_size);
-
-  return desc;
-}
-
 static void
 pango_cairo_core_text_font_finalize (GObject *object)
 {
@@ -191,10 +179,9 @@ pango_cairo_core_text_font_class_init (P
   PangoFontClass *font_class = PANGO_FONT_CLASS (class);
 
   object_class->finalize = pango_cairo_core_text_font_finalize;
-  /* font_class->describe defined by parent class PangoCoreTextFont. */
+
   font_class->get_glyph_extents = pango_cairo_core_text_font_get_glyph_extents;
   font_class->get_metrics = _pango_cairo_font_get_metrics;
-  font_class->describe_absolute = pango_cairo_core_text_font_describe_absolute;
 }
 
 static void
@@ -232,8 +219,6 @@ _pango_cairo_core_text_font_new (PangoCa
   cafont = g_object_new (PANGO_TYPE_CAIRO_CORE_TEXT_FONT, NULL);
   cfont = PANGO_CORE_TEXT_FONT (cafont);
 
-  cafont->abs_size = pango_core_text_font_key_get_size (key);
-
   _pango_core_text_font_set_ctfont (cfont, font_ref);
 
   if (synthesize_italic)
