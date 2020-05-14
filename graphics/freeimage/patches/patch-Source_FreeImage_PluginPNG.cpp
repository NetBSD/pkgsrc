$NetBSD: patch-Source_FreeImage_PluginPNG.cpp,v 1.1 2020/05/14 16:42:14 nia Exp $

Unbundle image libraries.

--- Source/FreeImage/PluginPNG.cpp.orig	2018-07-28 19:15:26.000000000 +0000
+++ Source/FreeImage/PluginPNG.cpp
@@ -40,8 +40,8 @@
 
 // ----------------------------------------------------------
 
-#include "../ZLib/zlib.h"
-#include "../LibPNG/png.h"
+#include <zlib.h>
+#include <png.h>
 
 // ----------------------------------------------------------
 
