$NetBSD: patch-Source_FreeImage_PluginWebP.cpp,v 1.1 2020/05/14 16:42:14 nia Exp $

Unbundle image libraries.

--- Source/FreeImage/PluginWebP.cpp.orig	2016-06-15 14:48:12.000000000 +0000
+++ Source/FreeImage/PluginWebP.cpp
@@ -24,9 +24,9 @@
 
 #include "../Metadata/FreeImageTag.h"
 
-#include "../LibWebP/src/webp/decode.h"
-#include "../LibWebP/src/webp/encode.h"
-#include "../LibWebP/src/webp/mux.h"
+#include <webp/decode.h>
+#include <webp/encode.h>
+#include <webp/mux.h>
 
 // ==========================================================
 // Plugin Interface
