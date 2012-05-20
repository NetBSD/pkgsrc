$NetBSD: patch-SDL__ttf.c,v 1.1 2012/05/20 10:06:19 ryoon Exp $

Patch provided in upstream bug report,
http://bugzilla.libsdl.org/show_bug.cgi?id=1433

--- SDL_ttf.c.orig	2012-01-15 04:44:08.000000000 +0000
+++ SDL_ttf.c
@@ -1747,7 +1747,7 @@ SDL_Surface* TTF_RenderGlyph_Shaded( TTF
 	/* Copy the character from the pixmap */
 	src = glyph->pixmap.buffer;
 	dst = (Uint8*) textbuf->pixels;
-	for ( row = 0; row < glyph->bitmap.rows; ++row ) {
+	for ( row = 0; row < glyph->pixmap.rows; ++row ) {
 		memcpy( dst, src, glyph->pixmap.width );
 		src += glyph->pixmap.pitch;
 		dst += textbuf->pitch;
