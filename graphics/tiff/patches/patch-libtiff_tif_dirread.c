$NetBSD: patch-libtiff_tif_dirread.c,v 1.2.2.3 2017/05/06 15:08:52 bsiegert Exp $

CVE-2017-7596
CVE-2017-7597
CVE-2017-7598
CVE-2017-7599
CVE-2017-7600
https://github.com/vadz/libtiff/commit/3cfd62d77c2a7e147a05bd678524c345fa9c2bb8
https://github.com/vadz/libtiff/commit/3144e57770c1e4d26520d8abee750f8ac8b75490

--- libtiff/tif_dirread.c.orig	2017-05-05 18:56:15.000000000 +0000
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
