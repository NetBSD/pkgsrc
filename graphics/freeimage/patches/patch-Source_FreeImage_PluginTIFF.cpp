$NetBSD: patch-Source_FreeImage_PluginTIFF.cpp,v 1.3 2021/07/11 04:08:06 markd Exp $

Unbundle image libraries.
handle openexr3

--- Source/FreeImage/PluginTIFF.cpp.orig	2018-07-28 12:24:44.000000000 +0000
+++ Source/FreeImage/PluginTIFF.cpp
@@ -37,9 +37,9 @@
 
 #include "FreeImage.h"
 #include "Utilities.h"
-#include "../LibTIFF4/tiffiop.h"
+#include <tiffio.h>
 #include "../Metadata/FreeImageTag.h"
-#include "../OpenEXR/Half/half.h"
+#include <Imath/half.h>
 
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
