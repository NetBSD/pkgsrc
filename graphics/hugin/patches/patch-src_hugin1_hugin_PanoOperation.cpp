$NetBSD: patch-src_hugin1_hugin_PanoOperation.cpp,v 1.1 2019/08/28 01:32:12 markd Exp $

work with exiv2-0.27.x

--- src/hugin1/hugin/PanoOperation.cpp.orig	2019-02-02 10:11:01.000000000 +0000
+++ src/hugin1/hugin/PanoOperation.cpp
@@ -36,8 +36,7 @@
 // workaround for a conflict between exiv2 and wxWidgets/CMake built
 #define HAVE_PID_T 1
 #endif
-#include <exiv2/exif.hpp>
-#include <exiv2/image.hpp>
+#include <exiv2/exiv2.hpp>
 #include "base_wx/LensTools.h"
 #include "base_wx/wxLensDB.h"
 #include "hugin/ResetDialog.h"
