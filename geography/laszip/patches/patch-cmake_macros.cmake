$NetBSD: patch-cmake_macros.cmake,v 1.1 2023/08/31 10:03:14 adam Exp $

Fix library name on Darwin.

--- cmake/macros.cmake.orig	2023-08-31 09:59:47.000000000 +0000
+++ cmake/macros.cmake
@@ -70,7 +70,7 @@ macro(LASZIP_ADD_LIBRARY _name)
         RUNTIME DESTINATION ${LASZIP_BIN_INSTALL_DIR}
         LIBRARY DESTINATION ${LASZIP_LIB_INSTALL_DIR}
         ARCHIVE DESTINATION ${LASZIP_LIB_INSTALL_DIR})
-    if (APPLE)
+    if (FALSE)
         set_target_properties(${_name} PROPERTIES INSTALL_NAME_DIR
             "@executable_path/../lib")
     endif()
