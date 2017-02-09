$NetBSD: patch-src_ImageEventBox.cpp,v 1.1 2017/02/09 00:22:35 joerg Exp $

--- src/ImageEventBox.cpp.orig	2017-01-08 18:51:01.889096829 +0000
+++ src/ImageEventBox.cpp
@@ -149,7 +149,7 @@ void ImageEventBox::LoadImage(	const Gli
 void ImageEventBox::ScaleImage( double scalefactor,
 								Gdk::InterpType interp_type)
 	{
-	if(ImagePixbuf_Original != 0 && loaded == true)
+	if(ImagePixbuf_Original && loaded == true)
 		{
 		int new_width   = (int)(scalefactor * (double)ImagePixbuf_Original->get_width());
 		int new_height  = (int)(scalefactor * (double)ImagePixbuf_Original->get_height());
@@ -176,7 +176,7 @@ void ImageEventBox::ScaleImage(	int widt
 								double * scalefactor,
 								Gdk::InterpType interp_type)
 	{
-	if(ImagePixbuf_Original != 0 && loaded == true)
+	if(ImagePixbuf_Original && loaded == true)
 		{
 		double ratioh = (double)height/(double)ImagePixbuf_Original->get_height();
 		double ratiow = (double)width/(double)ImagePixbuf_Original->get_width();
@@ -206,7 +206,7 @@ void ImageEventBox::ScaleImage2(	int wid
 								double * scalefactor,
 								Gdk::InterpType interp_type)
 	{
-	if(ImagePixbuf_Original != 0 && loaded == true)
+	if(ImagePixbuf_Original && loaded == true)
 		{
 		if( width <= ImagePixbuf_Original->get_width() || height <= ImagePixbuf_Original->get_height() )
 		    {
@@ -242,7 +242,7 @@ void ImageEventBox::ScaleImage2(	int wid
 // the rotation of the image
 void ImageEventBox::RotateImage(Gdk::PixbufRotation rotateby)
 	{
-	if(ImagePixbuf_Original != 0 && loaded == true)
+	if(ImagePixbuf_Original && loaded == true)
 		{
 		try
 			{
