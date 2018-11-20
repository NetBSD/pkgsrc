$NetBSD: patch-pango_pangocoretext-private.h,v 1.1 2018/11/20 08:34:43 maya Exp $
From 60df2b006e5d4553abc7bb5fe9a99539c91b0022 Mon Sep 17 00:00:00 2001
From: Tom Schoonjans <Tom.Schoonjans%diamond.ac.uk@localhost>
Date: Fri, 20 Jul 2018 12:30:34 +0100
Subject: [PATCH] Revert "Restore scaling of CoreText fonts."

This reverts commit f661cdbf8cfbdb2ba7241d8dfa4a579c6dfe0a94.

--- pango/pangocoretext-private.h.orig	2018-07-16 00:50:43.000000000 +0000
+++ pango/pangocoretext-private.h
@@ -99,8 +99,6 @@ void                  _pango_core_text_f
 PangoFontDescription *_pango_core_text_font_description_from_ct_font_descriptor (CTFontDescriptorRef desc);
 
 _PANGO_EXTERN
-int                   pango_core_text_font_key_get_size             (const PangoCoreTextFontKey *key);
-_PANGO_EXTERN
 int                   pango_core_text_font_key_get_size    (const PangoCoreTextFontKey *key);
 _PANGO_EXTERN
 double                pango_core_text_font_key_get_resolution       (const PangoCoreTextFontKey *key);
