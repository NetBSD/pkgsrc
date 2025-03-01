$NetBSD: patch-lib_jxl__cms.cmake,v 1.1 2025/03/01 12:16:44 adam Exp $

CMAKE_REQUIRED_LINK_OPTIONS is better suited for tests than CMAKE_EXE_LINKER_FLAGS.
https://github.com/libjxl/libjxl/pull/4133

--- lib/jxl_cms.cmake.orig	2025-03-01 11:49:41.937461307 +0000
+++ lib/jxl_cms.cmake
@@ -46,9 +46,9 @@ set_target_properties(jxl_cms PROPERTIES
 # Check whether the linker support excluding libs
 set(LINKER_EXCLUDE_LIBS_FLAG "-Wl,--exclude-libs=ALL")
 include(CheckCSourceCompiles)
-list(APPEND CMAKE_EXE_LINKER_FLAGS ${LINKER_EXCLUDE_LIBS_FLAG})
+list(APPEND CMAKE_REQUIRED_LINK_OPTIONS ${LINKER_EXCLUDE_LIBS_FLAG})
 check_c_source_compiles("int main(){return 0;}" LINKER_SUPPORT_EXCLUDE_LIBS)
-list(REMOVE_ITEM CMAKE_EXE_LINKER_FLAGS ${LINKER_EXCLUDE_LIBS_FLAG})
+list(REMOVE_ITEM CMAKE_REQUIRED_LINK_OPTIONS ${LINKER_EXCLUDE_LIBS_FLAG})
 
 if(LINKER_SUPPORT_EXCLUDE_LIBS)
   set_property(TARGET jxl_cms APPEND_STRING PROPERTY
