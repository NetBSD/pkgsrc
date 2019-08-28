$NetBSD: patch-src_hugin1_ptbatcher_FindPanoDialog.cpp,v 1.1 2019/08/28 01:32:12 markd Exp $

work with exiv2-0.27.x

--- src/hugin1/ptbatcher/FindPanoDialog.cpp.orig	2019-01-27 09:53:22.000000000 +0000
+++ src/hugin1/ptbatcher/FindPanoDialog.cpp
@@ -36,8 +36,7 @@
 // workaround for a conflict between exiv2 and wxWidgets/CMake built
 #define HAVE_PID_T 1
 #endif
-#include "exiv2/exiv2.hpp"
-#include "exiv2/preview.hpp"
+#include <exiv2/exiv2.hpp>
 #ifdef _WIN32
 #include <commctrl.h>
 #endif
