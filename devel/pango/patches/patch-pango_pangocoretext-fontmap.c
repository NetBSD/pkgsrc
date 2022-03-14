$NetBSD: patch-pango_pangocoretext-fontmap.c,v 1.4 2022/03/14 17:27:42 adam Exp $

Fix for -Werror=unused-but-set-variable.

--- pango/pangocoretext-fontmap.c.orig	2022-03-14 17:14:20.000000000 +0000
+++ pango/pangocoretext-fontmap.c
@@ -1696,10 +1696,8 @@ static PangoFont *
 pango_core_text_fontset_load_font (PangoCoreTextFontset *ctfontset,
                                    CTFontDescriptorRef   ctdescriptor)
 {
-  PangoCoreTextFontsetKey *key;
   PangoCoreTextFont *font;
 
-  key = pango_core_text_fontset_get_key (ctfontset);
 
   /* For now, we will default the fallbacks to not have synthetic italic,
    * in the future this may be improved.
