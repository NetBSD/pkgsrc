$NetBSD: patch-pango_pangocoretext-fontmap.c,v 1.1 2018/11/20 08:34:43 maya Exp $
From 60df2b006e5d4553abc7bb5fe9a99539c91b0022 Mon Sep 17 00:00:00 2001
From: Tom Schoonjans <Tom.Schoonjans%diamond.ac.uk@localhost>
Date: Fri, 20 Jul 2018 12:30:34 +0100
Subject: [PATCH] Revert "Restore scaling of CoreText fonts."

This reverts commit f661cdbf8cfbdb2ba7241d8dfa4a579c6dfe0a94.

--- pango/pangocoretext-fontmap.c.orig	2018-08-06 02:47:22.000000000 +0000
+++ pango/pangocoretext-fontmap.c
@@ -806,7 +806,6 @@ get_context_matrix (PangoContext *contex
 /*
  * Helper functions for PangoCoreTextFontsetKey
  */
-static const double ppi = 72.0; /* typographic points per inch */
 
 static double
 pango_core_text_font_map_get_resolution (PangoCoreTextFontMap *fontmap,
@@ -818,7 +817,7 @@ pango_core_text_font_map_get_resolution 
   /* FIXME: acquire DPI from CoreText using some deafault font */
   g_warning ("FIXME: returning default DPI");
 
-  return ppi;
+  return 72.0;
 }
 
 static int
@@ -827,16 +826,8 @@ get_scaled_size (PangoCoreTextFontMap   
                  const PangoFontDescription *desc)
 {
   double size = pango_font_description_get_size (desc);
-  PangoMatrix *matrix = pango_context_get_matrix (context);
-  double scale_factor = pango_matrix_get_font_scale_factor (matrix);
-  
-  if (!pango_font_description_get_size_is_absolute(desc))
-  {
-    double dpi = pango_core_text_font_map_get_resolution (fontmap, context);
-    size *= (dpi/ppi);
-  }
 
-  return .5 +  scale_factor * size;
+  return .5 + pango_matrix_get_font_scale_factor (pango_context_get_matrix (context)) * size;
 }
 
 
