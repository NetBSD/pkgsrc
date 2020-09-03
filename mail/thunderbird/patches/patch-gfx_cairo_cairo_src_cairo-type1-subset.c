$NetBSD: patch-gfx_cairo_cairo_src_cairo-type1-subset.c,v 1.1 2020/09/03 15:26:22 ryoon Exp $

--- gfx/cairo/cairo/src/cairo-type1-subset.c.orig	2020-08-28 21:32:36.000000000 +0000
+++ gfx/cairo/cairo/src/cairo-type1-subset.c
@@ -270,7 +270,7 @@ cairo_type1_font_subset_find_segments (c
 	font->eexec_segment = (char *) p + font->header_segment_size;
 	font->eexec_segment_is_ascii = TRUE;
 	for (i = 0; i < 4; i++) {
-	    if (!isxdigit(font->eexec_segment[i]))
+	    if (!isxdigit((unsigned char) font->eexec_segment[i]))
 		font->eexec_segment_is_ascii = FALSE;
 	}
     }
