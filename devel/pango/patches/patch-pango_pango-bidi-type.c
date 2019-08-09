$NetBSD: patch-pango_pango-bidi-type.c,v 1.1.2.2 2019/08/09 19:13:16 bsiegert Exp $

bidi: Be safer against bad input

Don't run off the end of an array that we
allocated to certain length.

CVE-2019-1010238

--- pango/pango-bidi-type.c.orig	2018-07-28 15:15:28.000000000 +0000
+++ pango/pango-bidi-type.c
@@ -179,8 +179,11 @@ pango_log2vis_get_embedding_levels (cons
   for (i = 0, p = text; p < text + length; p = g_utf8_next_char(p), i++)
     {
       gunichar ch = g_utf8_get_char (p);
-      FriBidiCharType char_type;
-      char_type = fribidi_get_bidi_type (ch);
+      FriBidiCharType char_type = fribidi_get_bidi_type (ch);
+
+      if (i == n_chars)
+        break;
+
       bidi_types[i] = char_type;
       ored_types |= char_type;
       if (FRIBIDI_IS_STRONG (char_type))
