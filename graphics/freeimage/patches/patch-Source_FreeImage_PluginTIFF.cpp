$NetBSD: patch-Source_FreeImage_PluginTIFF.cpp,v 1.1 2020/05/14 16:42:14 nia Exp $

Unbundle image libraries.

--- Source/FreeImage/PluginTIFF.cpp.orig	2018-07-28 23:24:44.000000000 +0000
+++ Source/FreeImage/PluginTIFF.cpp
@@ -37,9 +37,9 @@
 
 #include "FreeImage.h"
 #include "Utilities.h"
-#include "../LibTIFF4/tiffiop.h"
+#include <tiffio.h>
 #include "../Metadata/FreeImageTag.h"
-#include "../OpenEXR/Half/half.h"
+#include <OpenEXR/half.h>
 
 #include "FreeImageIO.h"
 #include "PSDParser.h"
@@ -194,16 +194,6 @@ TIFFFdOpen(thandle_t handle, const char 
 	return tif;
 }
 
-/**
-Open a TIFF file for reading or writing
-@param name
-@param mode
-*/
-TIFF*
-TIFFOpen(const char* name, const char* mode) {
-	return 0;
-}
-
 // ----------------------------------------------------------
 //   TIFF library FreeImage-specific routines.
 // ----------------------------------------------------------
