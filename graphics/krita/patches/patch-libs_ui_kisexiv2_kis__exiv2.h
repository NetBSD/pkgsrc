$NetBSD: patch-libs_ui_kisexiv2_kis__exiv2.h,v 1.1 2019/07/17 00:39:57 nia Exp $

Fix building against exiv2-0.27

Upstream commit:
https://github.com/KDE/krita/commit/6b6758bb37da4997be36a7e2a839b07278160559.patch

--- libs/ui/kisexiv2/kis_exiv2.h.orig	2018-09-26 12:18:03.000000000 +0000
+++ libs/ui/kisexiv2/kis_exiv2.h
@@ -21,7 +21,7 @@
 
 
 #include <metadata/kis_meta_data_value.h>
-#include <exiv2/value.hpp>
+#include <exiv2/exiv2.hpp>
 #include "kritaui_export.h"
 
 /// Convert an exiv value to a KisMetaData value
