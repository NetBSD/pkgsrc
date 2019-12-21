$NetBSD: patch-extensions_exiv2__tools_exiv2-utils.cpp,v 1.1 2019/12/21 23:43:26 joerg Exp $

--- extensions/exiv2_tools/exiv2-utils.cpp.orig	2019-12-21 22:44:56.297630474 +0000
+++ extensions/exiv2_tools/exiv2-utils.cpp
@@ -33,7 +33,8 @@
 #include <sstream>
 #include <vector>
 #include <iomanip>
-#include <exiv2/xmp.hpp>
+#include <exiv2/xmp_exiv2.hpp>
+#include <exiv2/version.hpp>
 #include <gthumb.h>
 #include "exiv2-utils.h"
 
@@ -898,7 +899,7 @@ dump_exif_data (Exiv2::ExifData &exifDat
 
 	try {
 		if (exifData.empty()) {
-			throw Exiv2::Error(1, " No Exif data found in the file");
+			throw Exiv2::Error(Exiv2::kerGeneralError, " No Exif data found in the file");
 		}
 		Exiv2::ExifData::const_iterator end = exifData.end();
 		for (Exiv2::ExifData::const_iterator i = exifData.begin(); i != end; ++i) {
