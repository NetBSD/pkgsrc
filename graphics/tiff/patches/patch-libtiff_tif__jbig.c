$NetBSD: patch-libtiff_tif__jbig.c,v 1.1.2.2 2018/10/26 07:02:56 spz Exp $

From 681748ec2f5ce88da5f9fa6831e1653e46af8a66 (CVE-2018-18557)

JBIGDecode doesn't check if the user provided buffer is large enough
to store the JBIG decoded image, which can potentially cause out-of-bounds
write in the buffer.
This issue was reported and analyzed by Thomas Dullien.

Also fixes a (harmless) potential use of uninitialized memory when
tif->tif_rawsize > tif->tif_rawcc

--- libtiff/tif_jbig.c.orig	2017-06-30 13:27:54.399206925 +0000
+++ libtiff/tif_jbig.c
@@ -53,17 +53,18 @@ static int JBIGDecode(TIFF* tif, uint8* 
 	struct jbg_dec_state decoder;
 	int decodeStatus = 0;
 	unsigned char* pImage = NULL;
-	(void) size, (void) s;
+	unsigned long decodedSize;
+	(void) s;
 
 	if (isFillOrder(tif, tif->tif_dir.td_fillorder))
 	{
-		TIFFReverseBits(tif->tif_rawdata, tif->tif_rawdatasize);
+		TIFFReverseBits(tif->tif_rawcp, tif->tif_rawcc);
 	}
 
 	jbg_dec_init(&decoder);
 
 #if defined(HAVE_JBG_NEWLEN)
-	jbg_newlen(tif->tif_rawdata, (size_t)tif->tif_rawdatasize);
+	jbg_newlen(tif->tif_rawcp, (size_t)tif->tif_rawcc);
 	/*
 	 * I do not check the return status of jbg_newlen because even if this
 	 * function fails it does not necessarily mean that decoding the image
@@ -76,8 +77,8 @@ static int JBIGDecode(TIFF* tif, uint8* 
 	 */
 #endif /* HAVE_JBG_NEWLEN */
 
-	decodeStatus = jbg_dec_in(&decoder, (unsigned char*)tif->tif_rawdata,
-				  (size_t)tif->tif_rawdatasize, NULL);
+	decodeStatus = jbg_dec_in(&decoder, (unsigned char*)tif->tif_rawcp,
+				  (size_t)tif->tif_rawcc, NULL);
 	if (JBG_EOK != decodeStatus)
 	{
 		/*
@@ -98,9 +99,28 @@ static int JBIGDecode(TIFF* tif, uint8* 
 		return 0;
 	}
 
+	decodedSize = jbg_dec_getsize(&decoder);
+	if( (tmsize_t)decodedSize < size )
+	{
+	    TIFFWarningExt(tif->tif_clientdata, "JBIG",
+	                   "Only decoded %lu bytes, whereas %lu requested",
+	                   decodedSize, (unsigned long)size);
+	}
+	else if( (tmsize_t)decodedSize > size )
+	{
+	    TIFFErrorExt(tif->tif_clientdata, "JBIG",
+	                 "Decoded %lu bytes, whereas %lu were requested",
+	                 decodedSize, (unsigned long)size);
+	    jbg_dec_free(&decoder);
+	    return 0;
+	}
 	pImage = jbg_dec_getimage(&decoder, 0);
-	_TIFFmemcpy(buffer, pImage, jbg_dec_getsize(&decoder));
+	_TIFFmemcpy(buffer, pImage, decodedSize);
 	jbg_dec_free(&decoder);
+
+        tif->tif_rawcp += tif->tif_rawcc;
+        tif->tif_rawcc = 0;
+
 	return 1;
 }
 
