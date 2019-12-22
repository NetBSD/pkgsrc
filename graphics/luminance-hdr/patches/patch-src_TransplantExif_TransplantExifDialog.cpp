$NetBSD: patch-src_TransplantExif_TransplantExifDialog.cpp,v 1.1 2019/12/22 22:26:32 joerg Exp $

--- src/TransplantExif/TransplantExifDialog.cpp.orig	2019-12-22 21:29:09.145132687 +0000
+++ src/TransplantExif/TransplantExifDialog.cpp
@@ -26,6 +26,8 @@
 #include <QFileInfo>
 #include <image.hpp>
 #include <exif.hpp>
+#include <exiv2/error.hpp>
+#include <exiv2/version.hpp>
 
 #include "Common/global.h"
 #include "Common/config.h"
