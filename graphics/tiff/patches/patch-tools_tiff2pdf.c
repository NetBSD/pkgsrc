$NetBSD: patch-tools_tiff2pdf.c,v 1.1 2012/07/19 21:41:45 wiz Exp $

CVE-2012-3401, buffer overflow in tiff2pdf

--- tools/tiff2pdf.c.orig	2012-06-15 21:51:54.000000000 +0000
+++ tools/tiff2pdf.c
@@ -1066,6 +1066,7 @@ void t2p_read_tiff_init(T2P* t2p, TIFF* 
 				"Can't set directory %u of input file %s", 
 				i,
 				TIFFFileName(input));
+			t2p->t2p_error = T2P_ERR_ERROR;
 			return;
 		}
 		if(TIFFGetField(input, TIFFTAG_PAGENUMBER, &pagen, &paged)){
