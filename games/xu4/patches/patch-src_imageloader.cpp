$NetBSD: patch-src_imageloader.cpp,v 1.1.1.1 2012/01/08 15:52:12 wiz Exp $

Add missing header.

--- src/imageloader.cpp.orig	2004-08-19 08:03:52.000000000 +0000
+++ src/imageloader.cpp
@@ -7,6 +7,7 @@
 #include "debug.h"
 #include "image.h"
 #include "imageloader.h"
+#include <stdlib.h>
 
 std::map<std::string, ImageLoader *> *ImageLoader::loaderMap = NULL;
 
