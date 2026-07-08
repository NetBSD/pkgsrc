$NetBSD: patch-cmakescripts_BuildPackages.cmake,v 1.1 2026/07/08 09:50:24 adam Exp $

Fix config scripts for ZLIB.
https://github.com/libjpeg-turbo/libjpeg-turbo/issues/901

--- cmakescripts/BuildPackages.cmake.orig	2026-07-08 09:32:34.411498672 +0000
+++ cmakescripts/BuildPackages.cmake
@@ -185,6 +185,11 @@ write_basic_package_version_file(
   pkgscripts/${CMAKE_PROJECT_NAME}ConfigVersion.cmake
   VERSION ${VERSION} COMPATIBILITY AnyNewerVersion)
 
+set(JPEGTURBO_CONFIG_DEPENDENCIES "")
+if(WITH_SYSTEM_ZLIB)
+  string(APPEND JPEGTURBO_CONFIG_DEPENDENCIES "find_dependency(ZLIB)\n")
+endif()
+
 configure_package_config_file(release/Config.cmake.in
   pkgscripts/${CMAKE_PROJECT_NAME}Config.cmake
   INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${CMAKE_PROJECT_NAME})
