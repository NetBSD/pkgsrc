$NetBSD: patch-cmake_PackageBundle.cmake,v 1.2 2026/01/02 14:28:27 triaxx Exp $

Let installed files inside ${LOCALBASE}.

--- cmake/PackageBundle.cmake.orig	2023-02-05 17:19:16.000000000 +0000
+++ cmake/PackageBundle.cmake
@@ -20,7 +20,7 @@ install(
     "
         include(BundleUtilities)
         set(BU_CHMOD_BUNDLE_ITEMS TRUE)
-        fixup_bundle(\"\${CMAKE_INSTALL_PREFIX}/../MacOS/openttd\"  \"\" \"\")
+        fixup_bundle(\"\${CMAKE_INSTALL_PREFIX}/bin/openttd\"  \"\" \"\")
     "
     DESTINATION .
     COMPONENT Runtime)
