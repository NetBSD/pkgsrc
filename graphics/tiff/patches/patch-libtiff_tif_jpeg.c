$NetBSD: patch-libtiff_tif_jpeg.c,v 1.1.2.2 2017/05/06 15:01:21 bsiegert Exp $

CVE-2017-7595
https://github.com/vadz/libtiff/commit/47f2fb61a3a64667bce1a8398a8fcb1b348ff122

CVE-2017-7601
https://github.com/vadz/libtiff/commit/0a76a8c765c7b8327c59646284fa78c3c27e5490

--- libtiff/tif_jpeg.c.orig	2017-05-03 22:26:09.000000000 +0000
+++ libtiff/tif_jpeg.c
@@ -1626,6 +1626,20 @@ JPEGSetupEncode(TIFF* tif)
 	case PHOTOMETRIC_YCBCR:
 		sp->h_sampling = td->td_ycbcrsubsampling[0];
 		sp->v_sampling = td->td_ycbcrsubsampling[1];
+                if( sp->h_sampling == 0 || sp->v_sampling == 0 )
+                {
+                    TIFFErrorExt(tif->tif_clientdata, module,
+                            "Invalig horizontal/vertical sampling value");
+                    return (0);
+                }
+                if( td->td_bitspersample > 16 )
+                {
+                    TIFFErrorExt(tif->tif_clientdata, module,
+                                 "BitsPerSample %d not allowed for JPEG",
+                                 td->td_bitspersample);
+                    return (0);
+                }
+
 		/*
 		 * A ReferenceBlackWhite field *must* be present since the
 		 * default value is inappropriate for YCbCr.  Fill in the
