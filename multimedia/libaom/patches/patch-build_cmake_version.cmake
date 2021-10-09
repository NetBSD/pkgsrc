$NetBSD: patch-build_cmake_version.cmake,v 1.2 2021/10/09 14:47:24 nia Exp $

Write the correct version number in the aom.pc file.

--- build/cmake/version.cmake.orig	2021-10-09 07:54:04.000000000 +0000
+++ build/cmake/version.cmake
@@ -23,28 +23,8 @@ include("${AOM_ROOT}/build/cmake/util.cm
 
 # Generate the version string for this run.
 unset(aom_version)
-if(EXISTS "${GIT_EXECUTABLE}")
-  execute_process(COMMAND ${GIT_EXECUTABLE} --git-dir=${AOM_ROOT}/.git describe
-                  OUTPUT_VARIABLE aom_version
-                  ERROR_QUIET
-                  RESULT_VARIABLE version_check_result)
 
-  if(${version_check_result} EQUAL 0)
-    string(STRIP "${aom_version}" aom_version)
-
-    # Remove the leading 'v' from the version string.
-    string(FIND "${aom_version}" "v" v_pos)
-    if(${v_pos} EQUAL 0)
-      string(SUBSTRING "${aom_version}" 1 -1 aom_version)
-    endif()
-  else()
-    set(aom_version "")
-  endif()
-endif()
-
-if("${aom_version}" STREQUAL "")
-  set(aom_version "${AOM_ROOT}/CHANGELOG")
-endif()
+set(aom_version "@PKGVERSION_NOREV@")
 
 unset(last_aom_version)
 set(version_file "${AOM_CONFIG_DIR}/config/aom_version.h")
