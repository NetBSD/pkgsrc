$NetBSD: patch-pango_pangocairo-coretextfontmap.c,v 1.1 2018/11/20 08:34:43 maya Exp $

From 60df2b006e5d4553abc7bb5fe9a99539c91b0022 Mon Sep 17 00:00:00 2001
From: Tom Schoonjans <Tom.Schoonjans%diamond.ac.uk@localhost>
Date: Fri, 20 Jul 2018 12:30:34 +0100
Subject: [PATCH] Revert "Restore scaling of CoreText fonts."

This reverts commit f661cdbf8cfbdb2ba7241d8dfa4a579c6dfe0a94.

--- pango/pangocairo-coretextfontmap.c.orig	2018-07-16 00:50:43.000000000 +0000
+++ pango/pangocairo-coretextfontmap.c
@@ -186,5 +186,5 @@ static void
 pango_cairo_core_text_font_map_init (PangoCairoCoreTextFontMap *cafontmap)
 {
   cafontmap->serial = 1;
-  cafontmap->dpi = 96.;
+  cafontmap->dpi = 72.;
 }
