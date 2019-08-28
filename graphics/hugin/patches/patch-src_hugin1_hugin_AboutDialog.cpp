$NetBSD: patch-src_hugin1_hugin_AboutDialog.cpp,v 1.1 2019/08/28 01:32:12 markd Exp $

work with exiv2-0.27.x

--- src/hugin1/hugin/AboutDialog.cpp.orig	2018-12-22 15:09:01.000000000 +0000
+++ src/hugin1/hugin/AboutDialog.cpp
@@ -42,7 +42,7 @@ extern "C"
 // workaround for a conflict between exiv2 and wxWidgets/CMake built
 #define HAVE_PID_T 1
 #endif
-#include "exiv2/exiv2.hpp"
+#include <exiv2/exiv2.hpp>
 #include "lensdb/LensDB.h"
 #include "sqlite3.h"
 #include <lcms2.h>
