$NetBSD: patch-libtiff_tif_ojpeg.c,v 1.2 2017/05/07 21:52:16 he Exp $

CVE-2017-7594
http://bugzilla.maptools.org/show_bug.cgi?id=2659
https://github.com/vadz/libtiff/commit/8283e4d1b7e5
https://github.com/vadz/libtiff/commit/2ea32f7372b6

CVE-2016-10267
http://bugzilla.maptools.org/show_bug.cgi?id=2611
https://github.com/vadz/libtiff/commit/43bc256d8ae44b92d2734a3c5bc73957a4d7c1ec

--- libtiff/tif_ojpeg.c.orig	2016-09-08 13:23:57.000000000 +0000
+++ libtiff/tif_ojpeg.c
@@ -244,6 +244,7 @@ typedef enum {
 
 typedef struct {
 	TIFF* tif;
+	int decoder_ok;
 	#ifndef LIBJPEG_ENCAP_EXTERNAL
 	JMP_BUF exit_jmpbuf;
 	#endif
@@ -722,6 +723,7 @@ OJPEGPreDecode(TIFF* tif, uint16 s)
 		}
 		sp->write_curstrile++;
 	}
+	sp->decoder_ok = 1;
 	return(1);
 }
 
@@ -784,8 +786,14 @@ OJPEGPreDecodeSkipScanlines(TIFF* tif)
 static int
 OJPEGDecode(TIFF* tif, uint8* buf, tmsize_t cc, uint16 s)
 {
+	static const char module[]="OJPEGDecode";
 	OJPEGState* sp=(OJPEGState*)tif->tif_data;
 	(void)s;
+	if( !sp->decoder_ok )
+	{
+	    TIFFErrorExt(tif->tif_clientdata,module,"Cannot decode: decoder not correctly initialized");
+	    return 0;
+        }
 	if (sp->libjpeg_jpeg_query_style==0)
 	{
 		if (OJPEGDecodeRaw(tif,buf,cc)==0)
@@ -1782,7 +1790,10 @@ OJPEGReadHeaderInfoSecTablesQTable(TIFF*
 			TIFFSeekFile(tif,sp->qtable_offset[m],SEEK_SET); 
 			p=(uint32)TIFFReadFile(tif,&ob[sizeof(uint32)+5],64);
 			if (p!=64)
+                        {
+                                _TIFFfree(ob);
 				return(0);
+                        }
 			sp->qtable[m]=ob;
 			sp->sof_tq[m]=m;
 		}
@@ -1846,7 +1857,10 @@ OJPEGReadHeaderInfoSecTablesDcTable(TIFF
 				rb[sizeof(uint32)+5+n]=o[n];
 			p=(uint32)TIFFReadFile(tif,&(rb[sizeof(uint32)+21]),q);
 			if (p!=q)
+                        {
+                                _TIFFfree(rb);
 				return(0);
+                        }
 			sp->dctable[m]=rb;
 			sp->sos_tda[m]=(m<<4);
 		}
@@ -1910,7 +1924,10 @@ OJPEGReadHeaderInfoSecTablesAcTable(TIFF
 				rb[sizeof(uint32)+5+n]=o[n];
 			p=(uint32)TIFFReadFile(tif,&(rb[sizeof(uint32)+21]),q);
 			if (p!=q)
+                        {
+                                _TIFFfree(rb);
 				return(0);
+                        }
 			sp->actable[m]=rb;
 			sp->sos_tda[m]=(sp->sos_tda[m]|m);
 		}
