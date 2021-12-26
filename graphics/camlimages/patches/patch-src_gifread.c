$NetBSD: patch-src_gifread.c,v 1.3 2021/12/26 05:28:23 dholland Exp $

- DGifOpenFileName API change for giflib-5
- DGifCloseFile API change for giflib-5.1
- PrintGifError API removal for giflib-4.2.0
- Update for immutable OCaml strings

--- src/gifread.c.orig	2011-06-22 18:04:32.000000000 +0000
+++ src/gifread.c
@@ -20,6 +20,12 @@
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
@@ -140,7 +146,7 @@ value dGifOpenFileName( value name )
   GifFileType *GifFile;
   int i;
 
-  if((GifFile = DGifOpenFileName( String_val(name) )) == NULL){
+  if((GifFile = DGifOpenFileName( String_val(name), NULL )) == NULL){
     failwith("DGifOpenFileName");
   }
 
@@ -161,7 +167,7 @@ value dGifCloseFile( value hdl )
      segmentation faults */
   ((GifFileType *)hdl)->Image.ColorMap = NULL; 
 
-  DGifCloseFile( (GifFileType *) hdl );
+  DGifCloseFile( (GifFileType *) hdl, NULL);
   CAMLreturn(Val_unit);
 }
 
@@ -196,11 +202,10 @@ value dGifGetLine( value hdl )
   if( oversized( GifFile->Image.Width, sizeof(GifPixelType) ) ){
     failwith_oversized("gif");
   }
-  buf = alloc_string( GifFile->Image.Width * sizeof(GifPixelType) ); 
+  buf = alloc_bytes( GifFile->Image.Width * sizeof(GifPixelType) ); 
 
-  if( DGifGetLine(GifFile, String_val(buf), GifFile->Image.Width ) 
+  if( DGifGetLine(GifFile, Bytes_val(buf), GifFile->Image.Width ) 
       == GIF_ERROR ){
-    PrintGifError ();
     failwith("DGifGetLine");
   }
   CAMLreturn(buf);
@@ -223,8 +228,7 @@ value dGifGetExtension( value hdl )
   }
 
   while( extData != NULL ){
-    ext= alloc_string(extData[0]);
-    memcpy(String_val(ext), &extData[1], extData[0]);
+    ext= caml_alloc_initialized_string(extData[0], &extData[1]);
     newres = alloc_small(2,0);
     Field(newres, 0)= ext;
     Field(newres, 1)= exts;
