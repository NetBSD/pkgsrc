$NetBSD: patch-cmake_FcitxMacro.cmake,v 1.1 2018/08/18 01:11:16 ryoon Exp $

--- cmake/FcitxMacro.cmake.orig	2017-12-22 18:02:24.000000000 +0000
+++ cmake/FcitxMacro.cmake
@@ -199,6 +199,7 @@ function(__fcitx_cmake_init)
   set(__FCITX_CMAKE_HELPER_EXPORT
     "_FCITX_MACRO_CMAKE_DIR=${FCITX_MACRO_CMAKE_DIR}"
     "_FCITX_PO_PARSER_EXECUTABLE=${FCITX_PO_PARSER_EXECUTABLE}"
+    "LD_LIBRARY_PATH=${PROJECT_BINARY_DIR}/src/lib/fcitx-utils"
     "FCITX_HELPER_CMAKE_CMD=${CMAKE_COMMAND}"
     "FCITX_CMAKE_CACHE_BASE=${fcitx_cmake_cache_base}"
     CACHE INTERNAL "fcitx cmake helper export" FORCE)
@@ -444,7 +445,7 @@ function(__fcitx_scan_addon name in_file
   get_filename_component(dir "${out_file}" PATH)
   add_custom_command(
     COMMAND "${CMAKE_COMMAND}" -E make_directory "${dir}"
-    COMMAND "${FCITX_SCANNER_EXECUTABLE}" --api "${in_file}" "${out_file}"
+    COMMAND "${CMAKE_COMMAND}" -E env "LD_LIBRARY_PATH=${PROJECT_BINARY_DIR}/src/lib/fcitx-utils" "${FCITX_SCANNER_EXECUTABLE}" --api "${in_file}" "${out_file}"
     OUTPUT "${out_file}" DEPENDS "${in_file}" "${FCITX_SCANNER_EXECUTABLE}"
     WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
   __fcitx_addon_get_unique_name("${name}--scan" target_name)
@@ -459,7 +460,7 @@ function(__fcitx_scan_addon_priv name in
   get_filename_component(dir "${out_file}" PATH)
   add_custom_command(
     COMMAND "${CMAKE_COMMAND}" -E make_directory "${dir}"
-    COMMAND "${FCITX_SCANNER_EXECUTABLE}" --private "${in_file}" "${out_file}"
+    COMMAND "${CMAKE_COMMAND}" -E env "LD_LIBRARY_PATH=${PROJECT_BINARY_DIR}/src/lib/fcitx-utils" "${FCITX_SCANNER_EXECUTABLE}" --private "${in_file}" "${out_file}"
     OUTPUT "${out_file}" DEPENDS "${in_file}" "${FCITX_SCANNER_EXECUTABLE}"
     WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
   __fcitx_addon_get_unique_name("${name}--scan-priv" target_name)
