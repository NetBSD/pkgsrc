$NetBSD: patch-libtiff_tif_dir.c,v 1.1.2.2 2017/05/06 15:08:52 bsiegert Exp $

CVE-2017-7596
CVE-2017-7597
CVE-2017-7599
CVE-2017-7600
https://github.com/vadz/libtiff/commit/3144e57770c1e4d26520d8abee750f8ac8b75490

--- libtiff/tif_dir.c.orig	2016-10-29 23:03:18.000000000 +0000
+++ libtiff/tif_dir.c
@@ -31,6 +31,7 @@
  * (and also some miscellaneous stuff)
  */
 #include "tiffiop.h"
+#include <float.h>
 
 /*
  * These are used in the backwards compatibility code...
@@ -154,6 +155,15 @@ bad:
 	return (0);
 }
 
+static float TIFFClampDoubleToFloat( double val )
+{
+    if( val > FLT_MAX )
+        return FLT_MAX;
+    if( val < -FLT_MAX )
+        return -FLT_MAX;
+    return (float)val;
+}
+
 static int
 _TIFFVSetField(TIFF* tif, uint32 tag, va_list ap)
 {
@@ -312,13 +322,13 @@ _TIFFVSetField(TIFF* tif, uint32 tag, va
         dblval = va_arg(ap, double);
         if( dblval < 0 )
             goto badvaluedouble;
-		td->td_xresolution = (float) dblval;
+		td->td_xresolution = TIFFClampDoubleToFloat( dblval );
 		break;
 	case TIFFTAG_YRESOLUTION:
         dblval = va_arg(ap, double);
         if( dblval < 0 )
             goto badvaluedouble;
-		td->td_yresolution = (float) dblval;
+		td->td_yresolution = TIFFClampDoubleToFloat( dblval );
 		break;
 	case TIFFTAG_PLANARCONFIG:
 		v = (uint16) va_arg(ap, uint16_vap);
@@ -327,10 +337,10 @@ _TIFFVSetField(TIFF* tif, uint32 tag, va
 		td->td_planarconfig = (uint16) v;
 		break;
 	case TIFFTAG_XPOSITION:
-		td->td_xposition = (float) va_arg(ap, double);
+		td->td_xposition = TIFFClampDoubleToFloat( va_arg(ap, double) );
 		break;
 	case TIFFTAG_YPOSITION:
-		td->td_yposition = (float) va_arg(ap, double);
+		td->td_yposition = TIFFClampDoubleToFloat( va_arg(ap, double) );
 		break;
 	case TIFFTAG_RESOLUTIONUNIT:
 		v = (uint16) va_arg(ap, uint16_vap);
