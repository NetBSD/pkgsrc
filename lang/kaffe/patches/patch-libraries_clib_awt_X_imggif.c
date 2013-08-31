$NetBSD: patch-libraries_clib_awt_X_imggif.c,v 1.1 2013/08/31 14:50:32 joerg Exp $

--- libraries/clib/awt/X/imggif.c.orig	2013-08-31 13:19:32.000000000 +0000
+++ libraries/clib/awt/X/imggif.c
@@ -255,7 +255,7 @@ readGifFile ( int infile )
 
   fileSrc.fd = infile;
 
-  if ( !(gf = DGifOpen( &fileSrc, readGifFileSource)) )
+  if ( !(gf = DGifOpen( &fileSrc, readGifFileSource, NULL)) )
 	return 0;
 
   img = readGif( gf);
@@ -278,7 +278,7 @@ readGifData ( unsigned char* buf, long l
   bufSrc.buf = bufSrc.p = buf;
   bufSrc.remain = len;
 
-  if ( !(gf = DGifOpen( &bufSrc, readGifBuffer)) )
+  if ( !(gf = DGifOpen( &bufSrc, readGifBuffer, NULL)) )
 	return 0;
 
   img = readGif( gf);
