$NetBSD: patch-src_hugin__base_panodata_SrcPanoImage.cpp,v 1.1 2019/08/28 01:32:12 markd Exp $

work with exiv2-0.27.x

--- src/hugin_base/panodata/SrcPanoImage.cpp.orig	2019-02-16 08:18:55.000000000 +0000
+++ src/hugin_base/panodata/SrcPanoImage.cpp
@@ -40,9 +40,7 @@
 #include <vigra/diff2d.hxx>
 #include <vigra/imageinfo.hxx>
 #include <hugin_utils/utils.h>
-#include <exiv2/exif.hpp>
-#include <exiv2/image.hpp>
-#include <exiv2/easyaccess.hpp>
+#include <exiv2/exiv2.hpp>
 #include <lensdb/LensDB.h>
 #include "Exiv2Helper.h"
 
