$NetBSD: patch-libtiff_tif_dirread.c,v 1.2.2.4 2017/05/11 17:47:20 bsiegert Exp $

CVE-2017-7596
CVE-2017-7597
CVE-2017-7598
CVE-2017-7599
CVE-2017-7600
https://github.com/vadz/libtiff/commit/3cfd62d77c2a7e147a05bd678524c345fa9c2bb8
https://github.com/vadz/libtiff/commit/3144e57770c1e4d26520d8abee750f8ac8b75490

and

CVE-2016-10270
http://bugzilla.maptools.org/show_bug.cgi?id=2608
https://github.com/vadz/libtiff/commit/9a72a69e035ee70ff5c41541c8c61cd97990d018

--- libtiff/tif_dirread.c.orig	2016-11-18 02:42:46.000000000 +0000
+++ libtiff/tif_dirread.c
@@ -40,6 +40,7 @@
  */
 
 #include "tiffiop.h"
+#include <float.h>
 
 #define IGNORE 0          /* tag placeholder used below */
 #define FAILED_FII    ((uint32) -1)
@@ -2406,7 +2407,14 @@ static enum TIFFReadDirEntryErr TIFFRead
 				ma=(double*)origdata;
 				mb=data;
 				for (n=0; n<count; n++)
-					*mb++=(float)(*ma++);
+                                {
+                                    double val = *ma++;
+                                    if( val > FLT_MAX )
+                                        val = FLT_MAX;
+                                    else if( val < -FLT_MAX )
+                                        val = -FLT_MAX;
+                                    *mb++=(float)val;
+                                }
 			}
 			break;
 	}
@@ -2872,7 +2880,10 @@ static enum TIFFReadDirEntryErr TIFFRead
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
@@ -2900,7 +2911,10 @@ static enum TIFFReadDirEntryErr TIFFRead
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
@@ -5502,8 +5516,7 @@ ChopUpSingleUncompressedStrip(TIFF* tif)
 	uint64 rowblockbytes;
 	uint64 stripbytes;
 	uint32 strip;
-	uint64 nstrips64;
-	uint32 nstrips32;
+	uint32 nstrips;
 	uint32 rowsperstrip;
 	uint64* newcounts;
 	uint64* newoffsets;
@@ -5534,18 +5547,17 @@ ChopUpSingleUncompressedStrip(TIFF* tif)
 	    return;
 
 	/*
-	 * never increase the number of strips in an image
+	 * never increase the number of rows per strip
 	 */
 	if (rowsperstrip >= td->td_rowsperstrip)
 		return;
-	nstrips64 = TIFFhowmany_64(bytecount, stripbytes);
-	if ((nstrips64==0)||(nstrips64>0xFFFFFFFF)) /* something is wonky, do nothing. */
+	nstrips = TIFFhowmany_32(td->td_imagelength, rowsperstrip);
+	if( nstrips == 0 )
 	    return;
-	nstrips32 = (uint32)nstrips64;
 
-	newcounts = (uint64*) _TIFFCheckMalloc(tif, nstrips32, sizeof (uint64),
+	newcounts = (uint64*) _TIFFCheckMalloc(tif, nstrips, sizeof (uint64),
 				"for chopped \"StripByteCounts\" array");
-	newoffsets = (uint64*) _TIFFCheckMalloc(tif, nstrips32, sizeof (uint64),
+	newoffsets = (uint64*) _TIFFCheckMalloc(tif, nstrips, sizeof (uint64),
 				"for chopped \"StripOffsets\" array");
 	if (newcounts == NULL || newoffsets == NULL) {
 		/*
@@ -5562,18 +5574,18 @@ ChopUpSingleUncompressedStrip(TIFF* tif)
 	 * Fill the strip information arrays with new bytecounts and offsets
 	 * that reflect the broken-up format.
 	 */
-	for (strip = 0; strip < nstrips32; strip++) {
+	for (strip = 0; strip < nstrips; strip++) {
 		if (stripbytes > bytecount)
 			stripbytes = bytecount;
 		newcounts[strip] = stripbytes;
-		newoffsets[strip] = offset;
+		newoffsets[strip] = stripbytes ? offset : 0;
 		offset += stripbytes;
 		bytecount -= stripbytes;
 	}
 	/*
 	 * Replace old single strip info with multi-strip info.
 	 */
-	td->td_stripsperimage = td->td_nstrips = nstrips32;
+	td->td_stripsperimage = td->td_nstrips = nstrips;
 	TIFFSetField(tif, TIFFTAG_ROWSPERSTRIP, rowsperstrip);
 
 	_TIFFfree(td->td_stripbytecount);
