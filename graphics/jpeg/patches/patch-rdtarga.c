$NetBSD: patch-rdtarga.c,v 1.1 2019/03/10 11:22:43 spz Exp $

fix for CVE-2018-11813 from
https://github.com/mozilla/mozjpeg/commit/909a8cfc7bca9b2e6707425bdb74da997e8fa499

--- rdtarga.c.orig	2017-09-16 11:12:46.000000000 +0000
+++ rdtarga.c
@@ -125,11 +125,10 @@ METHODDEF(void)
 read_non_rle_pixel (tga_source_ptr sinfo)
 /* Read one Targa pixel from the input file; no RLE expansion */
 {
-  register FILE *infile = sinfo->pub.input_file;
   register int i;
 
   for (i = 0; i < sinfo->pixel_size; i++) {
-    sinfo->tga_pixel[i] = (U_CHAR) getc(infile);
+    sinfo->tga_pixel[i] = (U_CHAR) read_byte(sinfo);
   }
 }
 
@@ -138,7 +137,6 @@ METHODDEF(void)
 read_rle_pixel (tga_source_ptr sinfo)
 /* Read one Targa pixel from the input file, expanding RLE data as needed */
 {
-  register FILE *infile = sinfo->pub.input_file;
   register int i;
 
   /* Duplicate previously read pixel? */
@@ -160,7 +158,7 @@ read_rle_pixel (tga_source_ptr sinfo)
 
   /* Read next pixel */
   for (i = 0; i < sinfo->pixel_size; i++) {
-    sinfo->tga_pixel[i] = (U_CHAR) getc(infile);
+    sinfo->tga_pixel[i] = (U_CHAR) read_byte(sinfo);
   }
 }
 
