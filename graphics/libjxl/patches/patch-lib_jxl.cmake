$NetBSD: patch-lib_jxl.cmake,v 1.2 2025/03/01 12:16:44 adam Exp $

CMAKE_REQUIRED_LINK_OPTIONS is better suited for tests than CMAKE_EXE_LINKER_FLAGS.
https://github.com/libjxl/libjxl/pull/4133

Not all linkers support --version-script, so test for it

--- lib/jxl.cmake.orig	2024-11-26 13:02:35.000000000 +0000
+++ lib/jxl.cmake
@@ -224,9 +224,14 @@ set_target_properties(jxl_dec PROPERTIES
 # Check whether the linker support excluding libs
 set(LINKER_EXCLUDE_LIBS_FLAG "-Wl,--exclude-libs=ALL")
 include(CheckCSourceCompiles)
-list(APPEND CMAKE_EXE_LINKER_FLAGS ${LINKER_EXCLUDE_LIBS_FLAG})
+list(APPEND CMAKE_REQUIRED_LINK_OPTIONS ${LINKER_EXCLUDE_LIBS_FLAG})
 check_c_source_compiles("int main(){return 0;}" LINKER_SUPPORT_EXCLUDE_LIBS)
-list(REMOVE_ITEM CMAKE_EXE_LINKER_FLAGS ${LINKER_EXCLUDE_LIBS_FLAG})
+list(REMOVE_ITEM CMAKE_REQUIRED_LINK_OPTIONS ${LINKER_VERSION_SCRIPT_FLAG})
+
+set(LINKER_VERSION_SCRIPT_FLAG "-Wl,--version-script=${CMAKE_CURRENT_SOURCE_DIR}/jxl/jxl.version")
+list(APPEND CMAKE_REQUIRED_LINK_OPTIONS ${LINKER_VERSION_SCRIPT_FLAG})
+check_c_source_compiles("int main(){return 0;}" LINKER_VERSION_SCRIPT)
+list(REMOVE_ITEM CMAKE_REQUIRED_LINK_OPTIONS ${LINKER_VERSION_SCRIPT_FLAG})
 
 if(NOT BUILD_SHARED_LIBS)
   target_compile_definitions(jxl PUBLIC -DJXL_STATIC_DEFINE)
@@ -245,8 +250,10 @@ foreach(target IN ITEMS jxl jxl_dec)
   elseif(WIN32)
     # Nothing needed here, we use __declspec(dllexport) (jxl_export.h)
   else()
+  if(LINKER_VERSION_SCRIPT)
   set_property(TARGET ${target} APPEND_STRING PROPERTY
       LINK_FLAGS " -Wl,--version-script=${CMAKE_CURRENT_SOURCE_DIR}/jxl/jxl.version")
+  endif(LINKER_VERSION_SCRIPT)
   endif()  # APPLE
   # This hides the default visibility symbols from static libraries bundled into
   # the shared library. In particular this prevents exposing symbols from hwy
