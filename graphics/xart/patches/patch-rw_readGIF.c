$NetBSD: patch-rw_readGIF.c,v 1.1 2011/12/05 22:48:59 joerg Exp $

--- rw/readGIF.c.orig	2011-12-05 20:25:31.000000000 +0000
+++ rw/readGIF.c
@@ -43,7 +43,7 @@ struct {
     unsigned int ColorResolution;
     unsigned int Background;
     unsigned int AspectRatio;
-    int GrayScale;
+    int GrayScale2;
 } GifScreen;
 
 static struct {
@@ -137,7 +137,7 @@ ReadGIF(char *file)
 
     if (BitSet(buf[4], LOCALCOLORMAP)) {	/* Global Colormap */
 	if (ReadColorMap(fd, GifScreen.BitPixel, GifScreen.ColorMap,
-			 &GifScreen.GrayScale)) {
+			 &GifScreen.GrayScale2)) {
 	    RWSetMsg("error reading global colormap");
 	    fclose(fd);
 	    return image;
@@ -193,7 +193,7 @@ ReadGIF(char *file)
 	    image = ReadImage(fd, LM_to_uint(buf[4], buf[5]),
 			      LM_to_uint(buf[6], buf[7]),
 			      GifScreen.BitPixel, GifScreen.ColorMap,
-			      GifScreen.GrayScale, BitSet(buf[8], INTERLACE),
+			      GifScreen.GrayScale2, BitSet(buf[8], INTERLACE),
 			      imageCount != imageNumber);
 	}
     }
