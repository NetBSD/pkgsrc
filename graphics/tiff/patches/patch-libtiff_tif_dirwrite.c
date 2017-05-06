$NetBSD: patch-libtiff_tif_dirwrite.c,v 1.1.2.2 2017/05/06 15:08:52 bsiegert Exp $

Dependency for applying advisory patch below without creating a variant.
http://bugzilla.maptools.org/show_bug.cgi?id=2535
https://github.com/vadz/libtiff/commit/0abd094b6e5079c4d8be733829240491cb230f3d

CVE-2017-7596
CVE-2017-7597
CVE-2017-7599
CVE-2017-7600
https://github.com/vadz/libtiff/commit/3144e57770c1e4d26520d8abee750f8ac8b75490

--- libtiff/tif_dirwrite.c.orig	2017-05-05 18:56:07.000000000 +0000
+++ libtiff/tif_dirwrite.c
@@ -30,6 +30,7 @@
  * Directory Write Support Routines.
  */
 #include "tiffiop.h"
+#include <float.h>
 
 #ifdef HAVE_IEEEFP
 #define TIFFCvtNativeToIEEEFloat(tif, n, fp)
@@ -939,6 +940,69 @@ bad:
 	return(0);
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
+static int8 TIFFClampDoubleToInt8( double val )
+{
+    if( val > 127 )
+        return 127;
+    if( val < -128 || val != val )
+        return -128;
+    return (int8)val;
+}
+
+static int16 TIFFClampDoubleToInt16( double val )
+{
+    if( val > 32767 )
+        return 32767;
+    if( val < -32768 || val != val )
+        return -32768;
+    return (int16)val;
+}
+
+static int32 TIFFClampDoubleToInt32( double val )
+{
+    if( val > 0x7FFFFFFF )
+        return 0x7FFFFFFF;
+    if( val < -0x7FFFFFFF-1 || val != val )
+        return -0x7FFFFFFF-1;
+    return (int32)val;
+}
+
+static uint8 TIFFClampDoubleToUInt8( double val )
+{
+    if( val < 0 )
+        return 0;
+    if( val > 255 || val != val )
+        return 255;
+    return (uint8)val;
+}
+
+static uint16 TIFFClampDoubleToUInt16( double val )
+{
+    if( val < 0 )
+        return 0;
+    if( val > 65535 || val != val )
+        return 65535;
+    return (uint16)val;
+}
+
+static uint32 TIFFClampDoubleToUInt32( double val )
+{
+    if( val < 0 )
+        return 0;
+    if( val > 0xFFFFFFFFU || val != val )
+        return 0xFFFFFFFFU;
+    return (uint32)val;
+}
+
 static int
 TIFFWriteDirectoryTagSampleformatArray(TIFF* tif, uint32* ndir, TIFFDirEntry* dir, uint16 tag, uint32 count, double* value)
 {
@@ -959,7 +1023,7 @@ TIFFWriteDirectoryTagSampleformatArray(T
 			if (tif->tif_dir.td_bitspersample<=32)
 			{
 				for (i = 0; i < count; ++i)
-					((float*)conv)[i] = (float)value[i];
+					((float*)conv)[i] = TIFFClampDoubleToFloat(value[i]);
 				ok = TIFFWriteDirectoryTagFloatArray(tif,ndir,dir,tag,count,(float*)conv);
 			}
 			else
@@ -971,19 +1035,19 @@ TIFFWriteDirectoryTagSampleformatArray(T
 			if (tif->tif_dir.td_bitspersample<=8)
 			{
 				for (i = 0; i < count; ++i)
-					((int8*)conv)[i] = (int8)value[i];
+					((int8*)conv)[i] = TIFFClampDoubleToInt8(value[i]);
 				ok = TIFFWriteDirectoryTagSbyteArray(tif,ndir,dir,tag,count,(int8*)conv);
 			}
 			else if (tif->tif_dir.td_bitspersample<=16)
 			{
 				for (i = 0; i < count; ++i)
-					((int16*)conv)[i] = (int16)value[i];
+					((int16*)conv)[i] = TIFFClampDoubleToInt16(value[i]);
 				ok = TIFFWriteDirectoryTagSshortArray(tif,ndir,dir,tag,count,(int16*)conv);
 			}
 			else
 			{
 				for (i = 0; i < count; ++i)
-					((int32*)conv)[i] = (int32)value[i];
+					((int32*)conv)[i] = TIFFClampDoubleToInt32(value[i]);
 				ok = TIFFWriteDirectoryTagSlongArray(tif,ndir,dir,tag,count,(int32*)conv);
 			}
 			break;
@@ -991,19 +1055,19 @@ TIFFWriteDirectoryTagSampleformatArray(T
 			if (tif->tif_dir.td_bitspersample<=8)
 			{
 				for (i = 0; i < count; ++i)
-					((uint8*)conv)[i] = (uint8)value[i];
+					((uint8*)conv)[i] = TIFFClampDoubleToUInt8(value[i]);
 				ok = TIFFWriteDirectoryTagByteArray(tif,ndir,dir,tag,count,(uint8*)conv);
 			}
 			else if (tif->tif_dir.td_bitspersample<=16)
 			{
 				for (i = 0; i < count; ++i)
-					((uint16*)conv)[i] = (uint16)value[i];
+					((uint16*)conv)[i] = TIFFClampDoubleToUInt16(value[i]);
 				ok = TIFFWriteDirectoryTagShortArray(tif,ndir,dir,tag,count,(uint16*)conv);
 			}
 			else
 			{
 				for (i = 0; i < count; ++i)
-					((uint32*)conv)[i] = (uint32)value[i];
+					((uint32*)conv)[i] = TIFFClampDoubleToUInt32(value[i]);
 				ok = TIFFWriteDirectoryTagLongArray(tif,ndir,dir,tag,count,(uint32*)conv);
 			}
 			break;
@@ -2094,15 +2158,25 @@ TIFFWriteDirectoryTagCheckedSlong8Array(
 static int
 TIFFWriteDirectoryTagCheckedRational(TIFF* tif, uint32* ndir, TIFFDirEntry* dir, uint16 tag, double value)
 {
+        static const char module[] = "TIFFWriteDirectoryTagCheckedRational";
 	uint32 m[2];
-	assert(value>=0.0);
 	assert(sizeof(uint32)==4);
-	if (value<=0.0)
+        if( value < 0 )
+        {
+            TIFFErrorExt(tif->tif_clientdata,module,"Negative value is illegal");
+            return 0;
+        }
+        else if( value != value )
+        {
+            TIFFErrorExt(tif->tif_clientdata,module,"Not-a-number value is illegal");
+            return 0;
+        }
+	else if (value==0.0)
 	{
 		m[0]=0;
 		m[1]=1;
 	}
-	else if (value==(double)(uint32)value)
+	else if (value <= 0xFFFFFFFFU && value==(double)(uint32)value)
 	{
 		m[0]=(uint32)value;
 		m[1]=1;
@@ -2143,12 +2217,13 @@ TIFFWriteDirectoryTagCheckedRationalArra
 	}
 	for (na=value, nb=m, nc=0; nc<count; na++, nb+=2, nc++)
 	{
-		if (*na<=0.0)
+		if (*na<=0.0 || *na != *na)
 		{
 			nb[0]=0;
 			nb[1]=1;
 		}
-		else if (*na==(float)(uint32)(*na))
+		else if (*na >= 0 && *na <= (float)0xFFFFFFFFU &&
+                         *na==(float)(uint32)(*na))
 		{
 			nb[0]=(uint32)(*na);
 			nb[1]=1;
