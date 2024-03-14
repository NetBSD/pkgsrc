$NetBSD: patch-cmake_modules_FindLibMyPaint.cmake,v 1.1 2024/03/14 20:02:57 markd Exp $

Comment out parts that make the build fail when this is an optional
package that we aren't including anyway.

--- cmake/modules/FindLibMyPaint.cmake.orig	2023-12-06 11:38:26.000000000 +0000
+++ cmake/modules/FindLibMyPaint.cmake
@@ -89,19 +89,19 @@ find_library(LibMyPaint_LIBRARY
     HINTS ${MYPAINT_PKGCONF_LIBRARY_DIRS} ${MYPAINT_PKGCONF_LIBDIR}
 )
 
-if (NOT LibMyPaint_VERSION)
-    file(READ ${LibMyPaint_INCLUDE_DIR}/config.h _version_content)
-
-    string(REGEX MATCH "#define PACKAGE_VERSION[ \t]+\"(.+)\"" _version_match ${_version_content})
-
-    if (_version_match)
-        set(LibMyPaint_VERSION "${CMAKE_MATCH_1}")
-    else()
-        if(NOT LibMyPaint_FIND_QUIETLY)
-            message(WARNING "Failed to get version information from ${LibMyPaint_INCLUDE_DIR}/config.h")
-        endif()
-    endif()
-endif()
+#if (NOT LibMyPaint_VERSION)
+#    file(READ ${LibMyPaint_INCLUDE_DIR}/config.h _version_content)
+#
+#    string(REGEX MATCH "#define PACKAGE_VERSION[ \t]+\"(.+)\"" _version_match ${_version_content})
+#
+#    if (_version_match)
+#        set(LibMyPaint_VERSION "${CMAKE_MATCH_1}")
+#    else()
+#        if(NOT LibMyPaint_FIND_QUIETLY)
+#            message(WARNING "Failed to get version information from ${LibMyPaint_INCLUDE_DIR}/config.h")
+#        endif()
+#    endif()
+#endif()
 
 if (LibMyPaint_INCLUDE_DIR AND LibMyPaint_LIBRARY)
     set(LibMyPaint_FOUND ON)
