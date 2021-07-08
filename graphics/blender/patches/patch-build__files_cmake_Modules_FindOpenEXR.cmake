$NetBSD: patch-build__files_cmake_Modules_FindOpenEXR.cmake,v 1.1 2021/07/08 21:25:31 markd Exp $

openexr3 patch

--- build_files/cmake/Modules/FindOpenEXR.cmake.orig	2020-08-31 11:59:44.000000000 +0000
+++ build_files/cmake/Modules/FindOpenEXR.cmake
@@ -34,11 +34,10 @@ ENDIF()
 SET(_openexr_libs_ver_init "2.0")
 
 SET(_openexr_FIND_COMPONENTS
-  Half
   Iex
-  IlmImf
-  IlmThread
   Imath
+  OpenEXR
+  IlmThread
 )
 
 SET(_openexr_SEARCH_DIRS
@@ -120,7 +119,7 @@ FIND_PACKAGE_HANDLE_STANDARD_ARGS(OpenEX
 IF(OPENEXR_FOUND)
   SET(OPENEXR_LIBRARIES ${_openexr_LIBRARIES})
   # Both include paths are needed because of dummy OSL headers mixing #include <OpenEXR/foo.h> and #include <foo.h> :(
-  SET(OPENEXR_INCLUDE_DIRS ${OPENEXR_INCLUDE_DIR} ${OPENEXR_INCLUDE_DIR}/OpenEXR)
+  SET(OPENEXR_INCLUDE_DIRS ${OPENEXR_INCLUDE_DIR} ${OPENEXR_INCLUDE_DIR}/OpenEXR ${OPENEXR_INCLUDE_DIR}/Imath)
 ENDIF()
 
 MARK_AS_ADVANCED(
