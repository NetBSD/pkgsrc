$NetBSD: patch-cmake_modules_Findcoordgen.cmake,v 1.1 2020/11/04 19:54:12 bsiegert Exp $

coordgenlibs does not install the template file, and it is not needed.

--- cmake/modules/Findcoordgen.cmake.orig	2020-05-08 15:38:02.000000000 +0000
+++ cmake/modules/Findcoordgen.cmake
@@ -6,7 +6,6 @@
 #
 # coordgen_INCLUDE_DIRS   - CoordGen's includes directory
 # coordgen_LIBRARIES      - CoordGen's shared libraries
-# coordgen_TEMPLATE_FILE  - CoordGen templates file
 #
 #
 
@@ -28,19 +27,9 @@ find_library(coordgen_LIBRARIES
 )
 message(STATUS "coordgen libraries set as '${coordgen_LIBRARIES}'")
 
-# Just in case, add parent directory above libraries to templates search hints
-get_filename_component(libs_parent_dir ${coordgen_LIBRARIES} PATH)
-find_file(coordgen_TEMPLATE_FILE
-    NAMES templates.mae
-    HINTS ${coordgen_DIR} ${libs_parent_dir}
-    PATH_SUFFIXES "share" "share/coordgen"
-    DOC "templates file for coordgen"
-)
-message(STATUS "coordgen templates file set as '${coordgen_TEMPLATE_FILE}'")
-
 find_package_handle_standard_args(coordgen FOUND_VAR coordgen_FOUND
                                   REQUIRED_VARS coordgen_INCLUDE_DIRS
-                                  coordgen_LIBRARIES coordgen_TEMPLATE_FILE)
+                                  coordgen_LIBRARIES)
 
 
 
