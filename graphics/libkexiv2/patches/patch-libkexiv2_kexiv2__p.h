$NetBSD: patch-libkexiv2_kexiv2__p.h,v 1.1 2019/11/02 13:51:12 maya Exp $

New exiv2 support.
from https://github.com/KDE/libkexiv2/commit/d1be9298c7f2b9c717cda154d41732f230ea13a6

--- libkexiv2/kexiv2_p.h.orig	2015-04-30 19:04:22.000000000 +0000
+++ libkexiv2/kexiv2_p.h
@@ -74,17 +74,7 @@
 #pragma GCC visibility push(default)
 #endif
 
-#include <exiv2/exv_conf.h>
-#include <exiv2/error.hpp>
-#include <exiv2/image.hpp>
-#include <exiv2/jpgimage.hpp>
-#include <exiv2/datasets.hpp>
-#include <exiv2/tags.hpp>
-#include <exiv2/preview.hpp>
-#include <exiv2/properties.hpp>
-#include <exiv2/types.hpp>
-#include <exiv2/exif.hpp>
-#include <exiv2/xmpsidecar.hpp>
+#include <exiv2/exiv2.hpp>
 
 // Check if Exiv2 support XMP
 
