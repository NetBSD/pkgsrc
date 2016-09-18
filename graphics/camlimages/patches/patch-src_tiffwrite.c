$NetBSD: patch-src_tiffwrite.c,v 1.2 2016/09/18 05:46:31 dholland Exp $

 - Both ocaml/caml/config.h and tiff.h define int32, uint32, etc.
The workaround of this name polution is to intentionally overwrite the
first caml definition with a garbage macro before tiff.h is included and
then unset it after the include.  After tiff version 4.0.1, the same hack
has to be applied to 64-bit types.

 - As of some newer ocaml there's no "uint32", only "uint32_t". The
first two hunks of this patch are probably no longer necessary.


--- src/tiffwrite.c.orig	2011-06-22 18:04:32.000000000 +0000
+++ src/tiffwrite.c
@@ -25,6 +25,8 @@
 #define uint16 uint16tiff
 #define int32 int32tiff
 #define uint32 uint32tiff
+#define int64 int64tiff
+#define uint64 uint64tiff
 
 #include <tiffio.h>
 
@@ -32,6 +34,8 @@
 #undef uint16
 #undef int32
 #undef uint32
+#undef int64
+#undef uint64
 
 extern value *imglib_error;
 
@@ -56,8 +60,8 @@ value open_tiff_file_for_write( value fi
     /* Resolution */
     /* FillOrder */
     
-    TIFFSetField(tif, TIFFTAG_IMAGEWIDTH, (uint32) image_width);
-    TIFFSetField(tif, TIFFTAG_IMAGELENGTH, (uint32) image_height);
+    TIFFSetField(tif, TIFFTAG_IMAGEWIDTH, (uint32_t) image_width);
+    TIFFSetField(tif, TIFFTAG_IMAGELENGTH, (uint32_t) image_height);
     TIFFSetField(tif, TIFFTAG_ORIENTATION, ORIENTATION_TOPLEFT);
     TIFFSetField(tif, TIFFTAG_SAMPLESPERPIXEL, 3);
     TIFFSetField(tif, TIFFTAG_BITSPERSAMPLE, 8);
