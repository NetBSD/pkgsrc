$NetBSD: patch-gif__image.C,v 1.1 2020/03/26 02:32:43 joerg Exp $

--- gif_image.C.orig	2020-03-25 13:57:03.791661713 +0000
+++ gif_image.C
@@ -58,8 +58,8 @@ GifImage::GifImage(const char *filename,
 : lockcount(0) {
 	first=0;
 	LoadGIF( filename );
-	name = strrchr(filename,'/');
-	if (name)	name=strdup(name+1);
+	const char *filename2 = strrchr(filename,'/');
+	if (filename2)	name=strdup(filename2+1);
 	else			name=strdup(filename);
 
 	if (autocrop&&!fastinfo_flag)	CropImage();
