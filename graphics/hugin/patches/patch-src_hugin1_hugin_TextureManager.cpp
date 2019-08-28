$NetBSD: patch-src_hugin1_hugin_TextureManager.cpp,v 1.1 2019/08/28 01:32:12 markd Exp $

work with exiv2-0.27.x

--- src/hugin1/hugin/TextureManager.cpp.orig	2019-02-28 17:21:39.000000000 +0000
+++ src/hugin1/hugin/TextureManager.cpp
@@ -65,8 +65,7 @@
 // workaround for a conflict between exiv2 and wxWidgets/CMake built
 #define HAVE_PID_T 1
 #endif
-#include "exiv2/exiv2.hpp"
-#include "exiv2/preview.hpp"
+#include <exiv2/exiv2.hpp>
 
 TextureManager::TextureManager(HuginBase::Panorama *pano, ViewState *view_state_in)
 {
