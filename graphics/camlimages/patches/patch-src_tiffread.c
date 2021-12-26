$NetBSD: patch-src_tiffread.c,v 1.3 2021/12/26 05:28:23 dholland Exp $

- ocaml/caml/compatibility.h defines int16 and uint16, which break tiff.
They're not needed, so clear them out. (There are no more int32/uint32
defines, so that logic can be removed.)

- tiff doesn't use "uint32" and "uint16" either any more, so use the
standard names.

- Use const.

- Update for OCaml immutable strings.

--- src/tiffread.c.orig	2011-06-22 18:04:32.000000000 +0000
+++ src/tiffread.c
@@ -23,11 +23,9 @@
 
 #include "oversized.h"
 
-/* These are defined in caml/config.h */
-#define int16 int16tiff
-#define uint16 uint16tiff
-#define int32 int32tiff
-#define uint32 uint32tiff
+/* These are defined in caml/compatibility.h and break tiff */
+#undef int16
+#undef uint16
 
 #include <tiffio.h>
 
@@ -40,22 +38,22 @@ value open_tiff_file_for_read( name )
   CAMLlocal1(res);
   CAMLlocalN(r,5);
 
-  char *filename; 
+  const char *filename;
   TIFF* tif;
   
   filename = String_val( name );
   
   tif = TIFFOpen(filename, "r");
   if (tif) {
-    uint32 imagelength;
-    uint32 imagewidth;
-    uint16 imagesample;
-    uint16 imagebits;
+    uint32_t imagelength;
+    uint32_t imagewidth;
+    uint16_t imagesample;
+    uint16_t imagebits;
     tdata_t buf;
     int i;
-    uint16 runit;
+    uint16_t runit;
     float xres, yres;
-    uint16 photometric;
+    uint16_t photometric;
 
     TIFFGetField(tif, TIFFTAG_IMAGELENGTH, &imagelength);
     TIFFGetField(tif, TIFFTAG_IMAGEWIDTH, &imagewidth);
@@ -114,7 +112,7 @@ value read_tiff_scanline( tiffh, buf, ro
      value row;
 {
   CAMLparam3(tiffh,buf,row);
-  TIFFReadScanline((TIFF*)tiffh, String_val(buf), Int_val(row), 0);
+  TIFFReadScanline((TIFF*)tiffh, Bytes_val(buf), Int_val(row), 0);
   CAMLreturn(Val_unit);
 }
 
