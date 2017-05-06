$NetBSD: patch-libtiff_tif_dirread.c,v 1.2.2.2 2017/05/06 15:01:21 bsiegert Exp $

CVE-2017-7598
https://github.com/vadz/libtiff/commit/3cfd62d77c2a7e147a05bd678524c345fa9c2bb8

--- libtiff/tif_dirread.c.orig	2016-11-18 02:42:46.000000000 +0000
+++ libtiff/tif_dirread.c
@@ -2872,7 +2872,10 @@ static enum TIFFReadDirEntryErr TIFFRead
 		m.l = direntry->tdir_offset.toff_long8;
 	if (tif->tif_flags&TIFF_SWAB)
 		TIFFSwabArrayOfLong(m.i,2);
-	if (m.i[0]==0)
+        /* Not completely sure what we should do when m.i[1]==0, but some */
+        /* sanitizers do not like division by 0.0: */
+        /* http://bugzilla.maptools.org/show_bug.cgi?id=2644 */
+	if (m.i[0]==0 || m.i[1]==0)
 		*value=0.0;
 	else
 		*value=(double)m.i[0]/(double)m.i[1];
@@ -2900,7 +2903,10 @@ static enum TIFFReadDirEntryErr TIFFRead
 		m.l=direntry->tdir_offset.toff_long8;
 	if (tif->tif_flags&TIFF_SWAB)
 		TIFFSwabArrayOfLong(m.i,2);
-	if ((int32)m.i[0]==0)
+        /* Not completely sure what we should do when m.i[1]==0, but some */
+        /* sanitizers do not like division by 0.0: */
+        /* http://bugzilla.maptools.org/show_bug.cgi?id=2644 */
+	if ((int32)m.i[0]==0 || m.i[1]==0)
 		*value=0.0;
 	else
 		*value=(double)((int32)m.i[0])/(double)m.i[1];
