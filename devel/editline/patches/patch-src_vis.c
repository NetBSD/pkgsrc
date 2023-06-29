$NetBSD: patch-src_vis.c,v 1.2 2023/06/29 17:55:29 hauke Exp $

vis(3): Avoid nonportable MIN in portable code.
Adopt upstream's resolution, to be dropped with the next update.

--- src/vis.c.orig	2022-06-11 07:56:37.000000000 +0000
+++ src/vis.c
@@ -468,7 +468,10 @@ istrsenvisx(char **mbdstp, size_t *dlen,
 	while (mbslength > 0) {
 		/* Convert one multibyte character to wchar_t. */
 		if (!cerr)
-			clen = mbrtowc(src, mbsrc, MIN(mbslength, MB_LEN_MAX),
+			clen = mbrtowc(src, mbsrc,
+			    (mbslength < MB_LEN_MAX
+				? mbslength
+				: MB_LEN_MAX),
 			    &mbstate);
 		if (cerr || clen < 0) {
 			/* Conversion error, process as a byte instead. */
