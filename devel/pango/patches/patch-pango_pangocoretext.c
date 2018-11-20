$NetBSD: patch-pango_pangocoretext.c,v 1.1 2018/11/20 08:34:43 maya Exp $
From 60df2b006e5d4553abc7bb5fe9a99539c91b0022 Mon Sep 17 00:00:00 2001
From: Tom Schoonjans <Tom.Schoonjans%diamond.ac.uk@localhost>
Date: Fri, 20 Jul 2018 12:30:34 +0100
Subject: [PATCH] Revert "Restore scaling of CoreText fonts."

This reverts commit f661cdbf8cfbdb2ba7241d8dfa4a579c6dfe0a94.

--- pango/pangocoretext.c.orig	2018-07-16 00:50:43.000000000 +0000
+++ pango/pangocoretext.c
@@ -225,7 +225,10 @@ pango_core_text_font_class_init (PangoCo
   object_class->finalize = pango_core_text_font_finalize;
 
   font_class->describe = pango_core_text_font_describe;
-  /* font_class->describe_absolute is left virtual for PangoCairoCoreTextFont. */
+  /* In CoreText the device unit is points so describe_absoulute and
+   * describe are the same.
+   */
+  font_class->describe_absolute = pango_core_text_font_describe;
   font_class->get_coverage = pango_core_text_font_get_coverage;
   font_class->find_shaper = pango_core_text_font_find_shaper;
   font_class->get_font_map = pango_core_text_font_get_font_map;
