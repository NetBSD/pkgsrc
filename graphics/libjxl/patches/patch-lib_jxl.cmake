$NetBSD: patch-lib_jxl.cmake,v 1.3 2026/07/02 03:13:36 adam Exp $

Not all linkers support --version-script, so test for it

--- lib/jxl.cmake.orig	2026-07-01 16:36:59.000000000 +0000
+++ lib/jxl.cmake
@@ -244,6 +244,11 @@ else()
   list(REMOVE_ITEM CMAKE_REQUIRED_LINK_OPTIONS ${LINKER_EXCLUDE_LIBS_FLAG})
 endif()
 
+set(LINKER_VERSION_SCRIPT_FLAG "-Wl,--version-script=${CMAKE_CURRENT_SOURCE_DIR}/jxl/jxl.version")
+list(APPEND CMAKE_REQUIRED_LINK_OPTIONS ${LINKER_VERSION_SCRIPT_FLAG})
+check_c_source_compiles("int main(){return 0;}" LINKER_VERSION_SCRIPT)
+list(REMOVE_ITEM CMAKE_REQUIRED_LINK_OPTIONS ${LINKER_VERSION_SCRIPT_FLAG})
+
 # Add a jxl.version file as a version script to tag symbols with the
 # appropriate version number. This script is also used to limit what's exposed
 # in the shared library from the static dependencies bundled here.
@@ -256,8 +261,10 @@ foreach(target IN ITEMS jxl jxl_dec)
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
