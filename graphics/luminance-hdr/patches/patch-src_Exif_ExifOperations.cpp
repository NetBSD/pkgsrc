$NetBSD: patch-src_Exif_ExifOperations.cpp,v 1.1 2019/12/22 22:26:32 joerg Exp $

--- src/Exif/ExifOperations.cpp.orig	2019-12-22 21:18:32.752281082 +0000
+++ src/Exif/ExifOperations.cpp
@@ -35,6 +35,7 @@
 #include <boost/assign/list_of.hpp>
 
 #include <exif.hpp>
+#include <exiv2/error.hpp>
 #include <image.hpp>
 
 #include "ExifOperations.h"
