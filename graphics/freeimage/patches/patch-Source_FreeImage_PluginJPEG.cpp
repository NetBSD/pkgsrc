$NetBSD: patch-Source_FreeImage_PluginJPEG.cpp,v 1.1 2020/05/14 16:42:14 nia Exp $

Unbundle image libraries.

--- Source/FreeImage/PluginJPEG.cpp.orig	2018-07-28 18:22:24.000000000 +0000
+++ Source/FreeImage/PluginJPEG.cpp
@@ -35,9 +35,9 @@ extern "C" {
 #undef FAR
 #include <setjmp.h>
 
-#include "../LibJPEG/jinclude.h"
-#include "../LibJPEG/jpeglib.h"
-#include "../LibJPEG/jerror.h"
+#include <stdio.h>
+#include <jpeglib.h>
+#include <jerror.h>
 }
 
 #include "FreeImage.h"
