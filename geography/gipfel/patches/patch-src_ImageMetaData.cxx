$NetBSD: patch-src_ImageMetaData.cxx,v 1.1 2020/03/20 20:46:04 joerg Exp $

--- src/ImageMetaData.cxx.orig	2020-03-20 19:11:56.000675904 +0000
+++ src/ImageMetaData.cxx
@@ -19,6 +19,7 @@
 
 #include <exiv2/image.hpp>
 #include <exiv2/exif.hpp>
+#include <exiv2/error.hpp>
 
 #include "../config.h"
 #include "ImageMetaData.H"
