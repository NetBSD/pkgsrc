$NetBSD: patch-graf2d_asimage_src_libAfterImage_import.c,v 1.1 2011/12/23 01:17:54 joerg Exp $

--- graf2d/asimage/src/libAfterImage/import.c.orig	2011-12-22 22:05:04.000000000 +0000
+++ graf2d/asimage/src/libAfterImage/import.c
@@ -1251,7 +1251,7 @@ png2ASImage_int( void *data, png_rw_ptr 
 			 * the normal method of doing things with libpng).  REQUIRED unless you
 			 * set up your own error handlers in the png_create_read_struct() earlier.
 			 */
-			if ( !setjmp (png_ptr->jmpbuf))
+			if ( !setjmp (png_jmpbuf(png_ptr)))
 			{
 				ASFlagType rgb_flags = ASStorage_RLEDiffCompress|ASStorage_32Bit ;
 
@@ -1468,7 +1468,7 @@ typedef struct ASImPNGReadBuffer
 
 static void asim_png_read_data(png_structp png_ptr, png_bytep data, png_size_t length)
 {
-   ASImPNGReadBuffer *buf = (ASImPNGReadBuffer *)png_ptr->io_ptr;
+   ASImPNGReadBuffer *buf = png_get_io_ptr(png_ptr);
    memcpy(data, buf->buffer, length);
    buf->buffer += length;
 }
