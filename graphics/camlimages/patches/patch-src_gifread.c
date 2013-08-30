$NetBSD: patch-src_gifread.c,v 1.1 2013/08/30 22:34:51 joerg Exp $

--- src/gifread.c.orig	2013-08-30 20:40:18.000000000 +0000
+++ src/gifread.c
@@ -140,7 +140,7 @@ value dGifOpenFileName( value name )
   GifFileType *GifFile;
   int i;
 
-  if((GifFile = DGifOpenFileName( String_val(name) )) == NULL){
+  if((GifFile = DGifOpenFileName( String_val(name), NULL )) == NULL){
     failwith("DGifOpenFileName");
   }
 
@@ -200,7 +200,6 @@ value dGifGetLine( value hdl )
 
   if( DGifGetLine(GifFile, String_val(buf), GifFile->Image.Width ) 
       == GIF_ERROR ){
-    PrintGifError ();
     failwith("DGifGetLine");
   }
   CAMLreturn(buf);
