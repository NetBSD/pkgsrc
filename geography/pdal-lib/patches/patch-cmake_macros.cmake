$NetBSD: patch-cmake_macros.cmake,v 1.1 2024/05/05 21:00:42 adam Exp $

On Darwin, don't use @rpath for install name.

--- cmake/macros.cmake.orig	2024-05-05 20:33:10.394857268 +0000
+++ cmake/macros.cmake
@@ -170,10 +170,6 @@ macro(PDAL_ADD_PLUGIN _name _type _short
         RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
         LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
         ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
-    if (APPLE)
-        set_target_properties(${${_name}} PROPERTIES
-            INSTALL_NAME_DIR "@rpath")
-    endif()
 endmacro(PDAL_ADD_PLUGIN)
 
 ###############################################################################
