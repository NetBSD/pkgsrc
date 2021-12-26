$NetBSD: patch-src_gifwrite.c,v 1.3 2021/12/26 05:28:23 dholland Exp $

- MakeMapObject API rename for giflib-5
- DGifOpenFileName API change for giflib-5
- DGifCloseFile API change for giflib-5.1
- PrintGifError API removal for giflib-4.2.0
- Don't use CAMLreturn for functions that aren't OCaml interfaces.
- Cast away const where OCaml provides it and giflib doesn't accept it.
- Update for OCaml immutable strings.

--- src/gifwrite.c.orig	2011-06-22 18:04:32.000000000 +0000
+++ src/gifwrite.c
@@ -44,7 +44,7 @@ ColorMapObject *ColorMapObject_val( valu
   int i;
   ColorMapObject *cmapobj;
 
-  if( cmap == Atom(0) ){ CAMLreturn(NULL); } 
+  if( cmap == Atom(0) ){ return NULL; } 
 
   len = Wosize_val(cmap);
 
@@ -52,13 +52,13 @@ ColorMapObject *ColorMapObject_val( valu
 fprintf(stderr, "Creating map with length = %d ...\n", len);
 fflush(stderr);
 */
-  cmapobj = MakeMapObject( len, NULL );
+  cmapobj = GifMakeMapObject( len, NULL );
   for(i=0; i< len; i++){
     cmapobj->Colors[i].Red   = Int_val(Field(Field(cmap,i),0));
     cmapobj->Colors[i].Green = Int_val(Field(Field(cmap,i),1));
     cmapobj->Colors[i].Blue  = Int_val(Field(Field(cmap,i),2));
   }
-  CAMLreturn(cmapobj); 
+  return cmapobj;
 }
 
 value eGifOpenFileName( name )
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
 
@@ -131,9 +131,8 @@ value eGifPutLine( value oc, value buf )
 
   GifFileType *GifFileOut = (GifFileType*) oc;
 
-  if ( EGifPutLine(GifFileOut, String_val(buf), GifFileOut->Image.Width) 
+  if ( EGifPutLine(GifFileOut, (char *)String_val(buf), GifFileOut->Image.Width) 
        == GIF_ERROR ){
-    PrintGifError ();
     failwith("EGifPutLine");
   }
   CAMLreturn(Val_unit);
