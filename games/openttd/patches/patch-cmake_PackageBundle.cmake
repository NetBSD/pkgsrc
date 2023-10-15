$NetBSD: patch-cmake_PackageBundle.cmake,v 1.1 2023/10/15 15:21:59 triaxx Exp $

Let installed files inside ${LOCALBASE}.

--- cmake/PackageBundle.cmake.orig	2023-02-05 17:19:16.000000000 +0000
+++ cmake/PackageBundle.cmake
@@ -19,7 +19,7 @@ install(
     "
         include(BundleUtilities)
         set(BU_CHMOD_BUNDLE_ITEMS TRUE)
-        fixup_bundle(\"\${CMAKE_INSTALL_PREFIX}/../MacOS/openttd\"  \"\" \"\")
+        fixup_bundle(\"\${CMAKE_INSTALL_PREFIX}/bin/openttd\"  \"\" \"\")
     "
     DESTINATION .
     COMPONENT Runtime)
