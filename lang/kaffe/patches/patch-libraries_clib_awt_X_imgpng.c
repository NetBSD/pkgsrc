$NetBSD: patch-libraries_clib_awt_X_imgpng.c,v 1.1 2011/04/05 11:49:51 wiz Exp $

Fix build with png-1.5.

--- libraries/clib/awt/X/imgpng.c.orig	2005-07-22 11:42:55.000000000 +0000
+++ libraries/clib/awt/X/imgpng.c
@@ -33,10 +33,10 @@ void reduceAlpha ( Toolkit* tk, Image* i
  */
 
 static inline int
-hasAlpha ( png_structp png_ptr )
+hasAlpha ( png_structp png_ptr, png_infop info_ptr )
 {
-  return  (png_ptr->color_type == PNG_COLOR_TYPE_GRAY_ALPHA ||
-		   png_ptr->color_type == PNG_COLOR_TYPE_RGB_ALPHA);
+  return  (png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_GRAY_ALPHA ||
+		   png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_RGB_ALPHA);
 
 }
 
@@ -78,13 +78,13 @@ readRowData ( png_structp png_ptr, png_i
   jint           argb;
   unsigned char  *p;
 
-  for ( i = 0; i < info_ptr->height; i++ ) {
+  for ( i = 0; i < png_get_image_height(png_ptr, info_ptr); i++ ) {
 	png_read_row( png_ptr, row, 0);
 
-	for ( j=0, p=(unsigned char*)row; j<info_ptr->width; j++ ) {
+	for ( j=0, p=(unsigned char*)row; j<png_get_image_width(png_ptr, info_ptr); j++ ) {
 	  argb = readARGB( &p,
 			   (img->alpha != 0)
-			   || (info_ptr->channels == 4));
+			   || (png_get_channels(png_ptr, info_ptr) == 4));
 	  setPixel( img, argb, i, j);
 	}
   }
@@ -99,8 +99,8 @@ readImageData ( png_structp png_ptr, png
 
   png_read_image( png_ptr, rows);
 
-  for ( i=0; i<info_ptr->height; i++ ) {
-	for ( j=0, p=(unsigned char*)rows[i]; j<info_ptr->width; j++ ) {
+  for ( i=0; i<png_get_image_height(png_ptr, info_ptr); i++ ) {
+	for ( j=0, p=(unsigned char*)rows[i]; j<png_get_image_width(png_ptr, info_ptr); j++ ) {
 	  argb = readARGB( &p, (img->alpha != 0));
 	  setPixel( img, argb, i, j);
 	}
@@ -145,13 +145,13 @@ readInterlacedData ( png_structp png_ptr
 
 
   for ( pass=0; pass<7; pass++ ) {
-	for ( i = 0; i < info_ptr->height; i++ ) {
+	for ( i = 0; i < png_get_image_height(png_ptr, info_ptr); i++ ) {
 	  if ( pass ) {
 		readbackRow( img, row, i);
 	  }
 	  png_read_row( png_ptr, row, 0);
 
-	  for ( j=0, p=(unsigned char*)row; j<info_ptr->width; j++ ) {
+	  for ( j=0, p=(unsigned char*)row; j<png_get_image_width(png_ptr, info_ptr); j++ ) {
 		argb = readARGB( &p, (img->alpha != 0));
 		setPixel( img, argb, i, j);
 	  }
@@ -171,7 +171,7 @@ readPng ( png_structp png_ptr, png_infop
   png_bytepp     volatile rows = 0;
   png_bytep      volatile data = 0;
 
-  if ( setjmp(png_ptr->jmpbuf) ) {
+  if ( setjmp(png_jmpbuf(png_ptr)) ) {
 	if ( img )
 	  imgFreeImage(img);
 	if ( rows )
@@ -212,21 +212,21 @@ readPng ( png_structp png_ptr, png_infop
   row_bytes     = png_get_rowbytes( png_ptr, info_ptr);
 
   /* time to create the image */
-  img = createImage( info_ptr->width, info_ptr->height);
-  if ( hasAlpha( png_ptr) )
+  img = createImage( png_get_image_width(png_ptr, info_ptr), png_get_image_height(png_ptr, info_ptr));
+  if ( hasAlpha( png_ptr, info_ptr ) )
 	createAlphaImage( X, img);
   createXImage( X, img);
 
-  if ( info_ptr->interlace_type != 0 ) {
+  if ( png_get_interlace_type(png_ptr, info_ptr) != 0 ) {
 #ifndef OPTIMIZE_SPACE
 	/*
 	 * This is bad: to read an interlaced image, we need enough space to (temporarily)
 	 * store the whole transformed data (passes need prev. results). Unfortunately,
 	 * interlacing is used for large images, and this might require a LOT of memory.
 	 */
-	rows = AWT_MALLOC( sizeof(png_bytep) * info_ptr->height);
-	data = AWT_MALLOC( row_bytes * info_ptr->height);
-	for ( i=0; i<info_ptr->height; i++ )
+	rows = AWT_MALLOC( sizeof(png_bytep) * png_get_image_height(png_ptr, info_ptr));
+	data = AWT_MALLOC( row_bytes * png_get_image_height(png_ptr, info_ptr));
+	for ( i=0; i<png_get_image_height(png_ptr, info_ptr); i++ )
 	  rows[i] = (data + i*row_bytes);
 
 	readImageData( png_ptr, info_ptr, rows, img);
