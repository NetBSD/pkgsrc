$NetBSD: patch-Source_FreeImage_PluginRAW.cpp,v 1.1 2020/05/14 16:42:14 nia Exp $

Unbundle image libraries.

--- Source/FreeImage/PluginRAW.cpp.orig	2015-03-10 11:12:04.000000000 +0000
+++ Source/FreeImage/PluginRAW.cpp
@@ -19,7 +19,7 @@
 // Use at your own risk!
 // ==========================================================
 
-#include "../LibRawLite/libraw/libraw.h"
+#include <libraw/libraw.h>
 
 #include "FreeImage.h"
 #include "Utilities.h"
