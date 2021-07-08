$NetBSD: patch-Source_FreeImage_PluginTIFF.cpp,v 1.2 2021/07/08 21:26:12 markd Exp $

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
+#include <Imath/half.h>
 
 #include "FreeImageIO.h"
 #include "PSDParser.h"
