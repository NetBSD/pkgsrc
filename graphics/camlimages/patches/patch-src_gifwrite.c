$NetBSD: patch-src_gifwrite.c,v 1.2 2014/05/24 04:05:24 obache Exp $

* MakeMapObject API rename for giflib-5
* DGifOpenFileName API change for giflib-5
* DGifCloseFile API change for giflib-5.1
* PrintGifError API removal for giflib-4.2.0

--- src/gifwrite.c.orig	2011-06-22 18:04:32.000000000 +0000
+++ src/gifwrite.c
@@ -52,7 +52,7 @@ ColorMapObject *ColorMapObject_val( valu
 fprintf(stderr, "Creating map with length = %d ...\n", len);
 fflush(stderr);
 */
-  cmapobj = MakeMapObject( len, NULL );
+  cmapobj = GifMakeMapObject( len, NULL );
   for(i=0; i< len; i++){
     cmapobj->Colors[i].Red   = Int_val(Field(Field(cmap,i),0));
     cmapobj->Colors[i].Green = Int_val(Field(Field(cmap,i),1));
@@ -68,7 +68,7 @@ value eGifOpenFileName( name )
 
   GifFileType *GifFileOut;
 
-  if ((GifFileOut = EGifOpenFileName( String_val( name ), 0) )== NULL) {
+  if ((GifFileOut = EGifOpenFileName( String_val( name ), 0, NULL) )== NULL) {
     failwith("EGifOpenFileName");
   }
   /* gcc -fwritable-strings is required to compile libungif */
@@ -88,7 +88,7 @@ value eGifCloseFile( value hdl )
      segmentation faults */
   ((GifFileType *)hdl)->Image.ColorMap = NULL; 
 
-  EGifCloseFile( (GifFileType *) hdl );
+  EGifCloseFile( (GifFileType *) hdl, NULL);
   CAMLreturn(Val_unit);
 }
 
@@ -133,7 +133,6 @@ value eGifPutLine( value oc, value buf )
 
   if ( EGifPutLine(GifFileOut, String_val(buf), GifFileOut->Image.Width) 
        == GIF_ERROR ){
-    PrintGifError ();
     failwith("EGifPutLine");
   }
   CAMLreturn(Val_unit);
