$NetBSD: patch-src_gifwrite.c,v 1.1 2013/08/30 22:34:51 joerg Exp $

--- src/gifwrite.c.orig	2013-08-30 20:37:28.000000000 +0000
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
@@ -133,7 +133,6 @@ value eGifPutLine( value oc, value buf )
 
   if ( EGifPutLine(GifFileOut, String_val(buf), GifFileOut->Image.Width) 
        == GIF_ERROR ){
-    PrintGifError ();
     failwith("EGifPutLine");
   }
   CAMLreturn(Val_unit);
