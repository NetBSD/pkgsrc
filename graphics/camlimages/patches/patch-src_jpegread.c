$NetBSD: patch-src_jpegread.c,v 1.2 2016/09/18 05:48:59 dholland Exp $

Make clang happy with proper return value

--- src/jpegread.c.orig	2011-06-22 18:04:32.000000000 +0000
+++ src/jpegread.c
@@ -417,7 +417,7 @@ value read_jpeg_scanlines( value jpegh, 
     jpeg_read_scanlines( cinfop, row, 1 );
     row[0] += scanline_bytes;
   }
-  CAMLreturn0;
+  CAMLreturn(Val_unit);
 }
 
 value close_jpeg_file_for_read( jpegh )
