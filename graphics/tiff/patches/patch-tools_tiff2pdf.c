$NetBSD: patch-tools_tiff2pdf.c,v 1.3.2.2 2017/05/11 17:47:20 bsiegert Exp $

Fix CVE-2016-10094, ref. http://bugzilla.maptools.org/show_bug.cgi?id=2640
and https://github.com/vadz/libtiff/commit/c7153361a4041260719b340f73f2f76

--- tools/tiff2pdf.c.orig	2016-11-12 14:58:09.000000000 +0000
+++ tools/tiff2pdf.c
@@ -2895,7 +2895,7 @@ tsize_t t2p_readwrite_pdf_image_tile(T2P
 				return(0);
 			}
 			if(TIFFGetField(input, TIFFTAG_JPEGTABLES, &count, &jpt) != 0) {
-				if (count >= 4) {
+				if (count > 4) {
                     /* Ignore EOI marker of JpegTables */
 					_TIFFmemcpy(buffer, jpt, count - 2);
 					bufferoffset += count - 2;
