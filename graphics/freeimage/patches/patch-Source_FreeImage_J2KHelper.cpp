$NetBSD: patch-Source_FreeImage_J2KHelper.cpp,v 1.1 2020/05/14 16:42:14 nia Exp $

Unbundle image libraries.

--- Source/FreeImage/J2KHelper.cpp.orig	2015-03-04 00:07:08.000000000 +0000
+++ Source/FreeImage/J2KHelper.cpp
@@ -21,7 +21,7 @@
 
 #include "FreeImage.h"
 #include "Utilities.h"
-#include "../LibOpenJPEG/openjpeg.h"
+#include <openjpeg.h>
 #include "J2KHelper.h"
 
 // --------------------------------------------------------------------------
