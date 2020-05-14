$NetBSD: patch-Source_FreeImage_PluginEXR.cpp,v 1.1 2020/05/14 16:42:14 nia Exp $

Unbundle image libraries.

--- Source/FreeImage/PluginEXR.cpp.orig	2015-03-04 00:07:08.000000000 +0000
+++ Source/FreeImage/PluginEXR.cpp
@@ -28,16 +28,16 @@
 #pragma warning (disable : 4800) // ImfVersion.h - 'const int' : forcing value to bool 'true' or 'false' (performance warning)
 #endif 
 
-#include "../OpenEXR/IlmImf/ImfIO.h"
-#include "../OpenEXR/Iex/Iex.h"
-#include "../OpenEXR/IlmImf/ImfOutputFile.h"
-#include "../OpenEXR/IlmImf/ImfInputFile.h"
-#include "../OpenEXR/IlmImf/ImfRgbaFile.h"
-#include "../OpenEXR/IlmImf/ImfChannelList.h"
-#include "../OpenEXR/IlmImf/ImfRgba.h"
-#include "../OpenEXR/IlmImf/ImfArray.h"
-#include "../OpenEXR/IlmImf/ImfPreviewImage.h"
-#include "../OpenEXR/Half/half.h"
+#include <OpenEXR/ImfIO.h>
+#include <OpenEXR/Iex.h>
+#include <OpenEXR/ImfOutputFile.h>
+#include <OpenEXR/ImfInputFile.h>
+#include <OpenEXR/ImfRgbaFile.h>
+#include <OpenEXR/ImfChannelList.h>
+#include <OpenEXR/ImfRgba.h>
+#include <OpenEXR/ImfArray.h>
+#include <OpenEXR/ImfPreviewImage.h>
+#include <OpenEXR/half.h>
 
 
 // ==========================================================
