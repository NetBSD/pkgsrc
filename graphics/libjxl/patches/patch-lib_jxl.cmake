$NetBSD: patch-lib_jxl.cmake,v 1.1 2025/02/04 11:22:48 wiz Exp $

All linkers do not support --version-script, so test for it

--- lib/jxl.cmake.orig	2024-01-05 16:54:25.540798120 +0000
+++ lib/jxl.cmake
@@ -216,6 +216,11 @@ list(APPEND CMAKE_EXE_LINKER_FLAGS ${LIN
 check_c_source_compiles("int main(){return 0;}" LINKER_SUPPORT_EXCLUDE_LIBS)
 list(REMOVE_ITEM CMAKE_EXE_LINKER_FLAGS ${LINKER_EXCLUDE_LIBS_FLAG})
 
+set(LINKER_VERSION_SCRIPT_FLAG "-Wl,--version-script=${CMAKE_CURRENT_SOURCE_DIR}/jxl/jxl.version")
+list(APPEND CMAKE_EXE_LINKER_FLAGS ${LINKER_VERSION_SCRIPT_FLAG})
+check_c_source_compiles("int main(){return 0;}" LINKER_VERSION_SCRIPT)
+list(REMOVE_ITEM CMAKE_EXE_LINKER_FLAGS ${LINKER_VERSION_SCRIPT_FLAG})
+
 if(NOT BUILD_SHARED_LIBS)
   target_compile_definitions(jxl PUBLIC -DJXL_STATIC_DEFINE)
   target_compile_definitions(jxl_dec PUBLIC -DJXL_STATIC_DEFINE)
@@ -233,8 +238,10 @@ foreach(target IN ITEMS jxl jxl_dec)
   elseif(WIN32)
     # Nothing needed here, we use __declspec(dllexport) (jxl_export.h)
   else()
+  if(LINKER_VERSION_SCRIPT)
   set_property(TARGET ${target} APPEND_STRING PROPERTY
       LINK_FLAGS " -Wl,--version-script=${CMAKE_CURRENT_SOURCE_DIR}/jxl/jxl.version")
+  endif()  # LINKER_VERSION_SCRIPT
   endif()  # APPLE
   # This hides the default visibility symbols from static libraries bundled into
   # the shared library. In particular this prevents exposing symbols from hwy
