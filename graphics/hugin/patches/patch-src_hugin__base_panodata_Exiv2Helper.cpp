$NetBSD: patch-src_hugin__base_panodata_Exiv2Helper.cpp,v 1.1 2019/08/28 01:32:12 markd Exp $

work with exiv2-0.27.x

--- src/hugin_base/panodata/Exiv2Helper.cpp.orig	2018-11-12 17:45:31.000000000 +0000
+++ src/hugin_base/panodata/Exiv2Helper.cpp
@@ -28,8 +28,7 @@
 #include "Exiv2Helper.h"
 #include "hugin_math/hugin_math.h"
 #include "hugin_utils/utils.h"  
-#include "exiv2/easyaccess.hpp"
-#include "exiv2/version.hpp"
+#include <exiv2/exiv2.hpp>
 
 namespace HuginBase
 {
