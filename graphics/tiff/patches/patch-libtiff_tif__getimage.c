$NetBSD: patch-libtiff_tif__getimage.c,v 1.1.2.2 2012/04/11 10:06:48 tron Exp $

Fix for CVE-2012-1173 from upstream.

--- libtiff/tif_getimage.c.orig	2011-02-25 03:34:02.000000000 +0000
+++ libtiff/tif_getimage.c
@@ -692,6 +692,7 @@ gtTileSeparate(TIFFRGBAImage* img, uint3
 	unsigned char* p2;
 	unsigned char* pa;
 	tmsize_t tilesize;
+	tmsize_t bufsize;
 	int32 fromskew, toskew;
 	int alpha = img->alpha;
 	uint32 nrow;
@@ -699,12 +700,17 @@ gtTileSeparate(TIFFRGBAImage* img, uint3
         int colorchannels;
 
 	tilesize = TIFFTileSize(tif);  
-	buf = (unsigned char*) _TIFFmalloc((alpha?4:3)*tilesize);
+	bufsize = TIFFSafeMultiply(tmsize_t,alpha?4:3,tilesize);
+	if (bufsize == 0) {
+		TIFFErrorExt(tif->tif_clientdata, TIFFFileName(tif), "Integer overflow in %s", "gtTileSeparate");
+		return (0);
+	}
+	buf = (unsigned char*) _TIFFmalloc(bufsize);
 	if (buf == 0) {
 		TIFFErrorExt(tif->tif_clientdata, TIFFFileName(tif), "%s", "No space for tile buffer");
 		return (0);
 	}
-	_TIFFmemset(buf, 0, (alpha?4:3)*tilesize);
+	_TIFFmemset(buf, 0, bufsize);
 	p0 = buf;
 	p1 = p0 + tilesize;
 	p2 = p1 + tilesize;
@@ -917,17 +923,23 @@ gtStripSeparate(TIFFRGBAImage* img, uint
 	uint32 rowsperstrip, offset_row;
 	uint32 imagewidth = img->width;
 	tmsize_t stripsize;
+	tmsize_t bufsize;
 	int32 fromskew, toskew;
 	int alpha = img->alpha;
 	int ret = 1, flip, colorchannels;
 
 	stripsize = TIFFStripSize(tif);  
-	p0 = buf = (unsigned char *)_TIFFmalloc((alpha?4:3)*stripsize);
+	bufsize = TIFFSafeMultiply(tmsize_t,alpha?4:3,stripsize);
+	if (bufsize == 0) {
+		TIFFErrorExt(tif->tif_clientdata, TIFFFileName(tif), "Integer overflow in %s", "gtStripSeparate");
+		return (0);
+	}
+	p0 = buf = (unsigned char *)_TIFFmalloc(bufsize);
 	if (buf == 0) {
 		TIFFErrorExt(tif->tif_clientdata, TIFFFileName(tif), "No space for tile buffer");
 		return (0);
 	}
-	_TIFFmemset(buf, 0, (alpha?4:3)*stripsize);
+	_TIFFmemset(buf, 0, bufsize);
 	p1 = p0 + stripsize;
 	p2 = p1 + stripsize;
 	pa = (alpha?(p2+stripsize):NULL);
