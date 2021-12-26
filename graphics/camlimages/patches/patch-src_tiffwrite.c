$NetBSD: patch-src_tiffwrite.c,v 1.3 2021/12/26 05:28:23 dholland Exp $

- ocaml/caml/compatibility.h defines int16 and uint16, which break tiff.
They're not needed, so clear them out. (There are no more int32/uint32
defines, so that logic can be removed.)

- tiff uses uint32_t instead of its own uint32 these days.

- Cast away const where ocaml provides const and tiff doesn't accept it.

--- src/tiffwrite.c.orig	2011-06-22 18:04:32.000000000 +0000
+++ src/tiffwrite.c
@@ -20,18 +20,11 @@
 #include <caml/memory.h>
 #include <caml/fail.h>
 
-/* These are defined in caml/config.h */
-#define int16 int16tiff
-#define uint16 uint16tiff
-#define int32 int32tiff
-#define uint32 uint32tiff
-
-#include <tiffio.h>
-
+/* These are defined in caml/compatibility.h and break tiff */
 #undef int16
 #undef uint16
-#undef int32
-#undef uint32
+
+#include <tiffio.h>
 
 extern value *imglib_error;
 
@@ -56,8 +49,8 @@ value open_tiff_file_for_write( value fi
     /* Resolution */
     /* FillOrder */
     
-    TIFFSetField(tif, TIFFTAG_IMAGEWIDTH, (uint32) image_width);
-    TIFFSetField(tif, TIFFTAG_IMAGELENGTH, (uint32) image_height);
+    TIFFSetField(tif, TIFFTAG_IMAGEWIDTH, (uint32_t) image_width);
+    TIFFSetField(tif, TIFFTAG_IMAGELENGTH, (uint32_t) image_height);
     TIFFSetField(tif, TIFFTAG_ORIENTATION, ORIENTATION_TOPLEFT);
     TIFFSetField(tif, TIFFTAG_SAMPLESPERPIXEL, 3);
     TIFFSetField(tif, TIFFTAG_BITSPERSAMPLE, 8);
@@ -83,6 +76,6 @@ value write_tiff_scanline( tiffh, buf, r
      value row;
 {
   CAMLparam3(tiffh,buf,row);
-  TIFFWriteScanline((TIFF*)tiffh, String_val(buf), Int_val(row), 0);
+  TIFFWriteScanline((TIFF*)tiffh, (char *)String_val(buf), Int_val(row), 0);
   CAMLreturn(Val_unit);
 }
