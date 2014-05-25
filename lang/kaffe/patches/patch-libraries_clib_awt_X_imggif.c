$NetBSD: patch-libraries_clib_awt_X_imggif.c,v 1.2 2014/05/25 08:24:24 obache Exp $

* Adapt to giflib>=5 API changes

--- libraries/clib/awt/X/imggif.c.orig	2005-07-22 11:42:55.000000000 +0000
+++ libraries/clib/awt/X/imggif.c
@@ -255,12 +255,12 @@ readGifFile ( int infile )
 
   fileSrc.fd = infile;
 
-  if ( !(gf = DGifOpen( &fileSrc, readGifFileSource)) )
+  if ( !(gf = DGifOpen( &fileSrc, readGifFileSource, NULL)) )
 	return 0;
 
   img = readGif( gf);
 
-  DGifCloseFile( gf);
+  DGifCloseFile( gf, NULL);
 #endif
 
   return img;
@@ -278,12 +278,12 @@ readGifData ( unsigned char* buf, long l
   bufSrc.buf = bufSrc.p = buf;
   bufSrc.remain = len;
 
-  if ( !(gf = DGifOpen( &bufSrc, readGifBuffer)) )
+  if ( !(gf = DGifOpen( &bufSrc, readGifBuffer, NULL)) )
 	return 0;
 
   img = readGif( gf);
 
-  DGifCloseFile( gf);
+  DGifCloseFile( gf, NULL);
   
 #endif /* INCLUDE_GIF */
 
