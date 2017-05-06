$NetBSD: patch-libtiff_tif_ojpeg.c,v 1.1.2.2 2017/05/06 15:01:21 bsiegert Exp $

CVE-2017-7594
http://bugzilla.maptools.org/show_bug.cgi?id=2659
https://github.com/vadz/libtiff/commit/8283e4d1b7e5
https://github.com/vadz/libtiff/commit/2ea32f7372b6

--- libtiff/tif_ojpeg.c.orig	2017-05-03 22:08:50.000000000 +0000
+++ libtiff/tif_ojpeg.c
@@ -1782,7 +1782,10 @@ OJPEGReadHeaderInfoSecTablesQTable(TIFF*
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
@@ -1846,7 +1849,10 @@ OJPEGReadHeaderInfoSecTablesDcTable(TIFF
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
@@ -1910,7 +1916,10 @@ OJPEGReadHeaderInfoSecTablesAcTable(TIFF
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
