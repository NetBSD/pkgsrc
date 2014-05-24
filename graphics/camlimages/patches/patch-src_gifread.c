$NetBSD: patch-src_gifread.c,v 1.2 2014/05/24 04:05:24 obache Exp $

* DGifOpenFileName API change for giflib-5
* DGifCloseFile API change for giflib-5.1
* PrintGifError API removal for giflib-4.2.0

--- src/gifread.c.orig	2011-06-22 18:04:32.000000000 +0000
+++ src/gifread.c
@@ -140,7 +140,7 @@ value dGifOpenFileName( value name )
   GifFileType *GifFile;
   int i;
 
-  if((GifFile = DGifOpenFileName( String_val(name) )) == NULL){
+  if((GifFile = DGifOpenFileName( String_val(name), NULL )) == NULL){
     failwith("DGifOpenFileName");
   }
 
@@ -161,7 +161,7 @@ value dGifCloseFile( value hdl )
      segmentation faults */
   ((GifFileType *)hdl)->Image.ColorMap = NULL; 
 
-  DGifCloseFile( (GifFileType *) hdl );
+  DGifCloseFile( (GifFileType *) hdl, NULL);
   CAMLreturn(Val_unit);
 }
 
@@ -200,7 +200,6 @@ value dGifGetLine( value hdl )
 
   if( DGifGetLine(GifFile, String_val(buf), GifFile->Image.Width ) 
       == GIF_ERROR ){
-    PrintGifError ();
     failwith("DGifGetLine");
   }
   CAMLreturn(buf);
