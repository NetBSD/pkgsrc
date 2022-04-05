$NetBSD: patch-src_cairo-type1-subset.c,v 1.1 2022/04/05 10:06:41 riastradh Exp $

Fix ctype(3) abuse.

--- src/cairo-type1-subset.c.orig	2018-08-17 01:10:53.000000000 +0000
+++ src/cairo-type1-subset.c
@@ -248,7 +248,7 @@ cairo_type1_font_subset_find_segments (c
 	font->eexec_segment = (char *) p + font->header_segment_size;
 	font->eexec_segment_is_ascii = TRUE;
 	for (i = 0; i < 4; i++) {
-	    if (!isxdigit(font->eexec_segment[i]))
+	    if (!isxdigit((unsigned char)font->eexec_segment[i]))
 		font->eexec_segment_is_ascii = FALSE;
 	}
     }
