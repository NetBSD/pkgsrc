$NetBSD: patch-src_jpegread.c,v 1.3 2021/12/26 05:28:23 dholland Exp $

Use const.

Update for OCaml immutable strings.

--- src/jpegread.c.orig	2011-06-22 18:04:32.000000000 +0000
+++ src/jpegread.c
@@ -23,6 +23,12 @@
 #include <caml/memory.h>
 #include <caml/fail.h>
 
+/*
+ * For future-proofing: currently in the ocaml FFI you use
+ * alloc_string for Bytes.t but that could change...
+ */
+#define alloc_bytes alloc_string
+
 #include "oversized.h"
 
 #include <stdio.h>
@@ -76,7 +82,7 @@ read_JPEG_file (value name)
   CAMLparam1(name);
   CAMLlocal1(res);
 
-  char *filename;
+  const char *filename;
   /* This struct contains the JPEG decompression parameters and pointers to
    * working space (which is allocated as needed by the JPEG library).
    */
@@ -198,9 +204,9 @@ read_JPEG_file (value name)
     CAMLlocalN(r,3);
     r[0] = Val_int(cinfo.output_width);
     r[1] = Val_int(cinfo.output_height);
-    r[2] = alloc_string ( row_stride * cinfo.output_height );
+    r[2] = alloc_bytes ( row_stride * cinfo.output_height );
     for(i=0; i<cinfo.output_height; i++){
-      memcpy( String_val(r[2]) + i * row_stride, 
+      memcpy( Bytes_val(r[2]) + i * row_stride, 
 	       buffer[i], row_stride);
     }
     res = alloc_tuple(3);
@@ -253,7 +259,7 @@ value open_jpeg_file_for_read( name )
   CAMLparam1(name);
   CAMLlocal1(res);
 
-  char *filename;
+  const char *filename;
   /* This struct contains the JPEG decompression parameters and pointers to
    * working space (which is allocated as needed by the JPEG library).
    */
@@ -395,7 +401,7 @@ value jpegh, offset, buf;
   JSAMPROW row[1];
 
   cinfop = (struct jpeg_decompress_struct *) Field( jpegh, 0 );
-  row[0] = String_val( buf ) + Int_val( offset );
+  row[0] = Bytes_val( buf ) + Int_val( offset );
   jpeg_read_scanlines( cinfop, row, 1 );
 
   CAMLreturn(Val_unit);
@@ -409,7 +415,7 @@ value read_jpeg_scanlines( value jpegh, 
   JSAMPROW row[1];
   int clines = Int_val(lines);
   int i;
-  row[0] = String_val(buf) + Int_val(offset);
+  row[0] = Bytes_val(buf) + Int_val(offset);
   cinfop = (struct jpeg_decompress_struct *) Field( jpegh, 0 );
   // width is NOT image_width since we may have scale_denom <> 1
   int scanline_bytes = cinfop->output_width * 3; // no padding (size 3 is fixed? )
@@ -417,7 +423,7 @@ value read_jpeg_scanlines( value jpegh, 
     jpeg_read_scanlines( cinfop, row, 1 );
     row[0] += scanline_bytes;
   }
-  CAMLreturn0;
+  CAMLreturn(Val_unit);
 }
 
 value close_jpeg_file_for_read( jpegh )
