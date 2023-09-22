$NetBSD: patch-cmake_QoreMacros.cmake,v 1.1 2023/09/22 07:10:07 nros Exp $

* "-undefined dynamic_lookup" seems to be Apple ld specific but tolerated by GNU ld,
  using it breaks the linking stage of qore modules on Illumos

--- cmake/QoreMacros.cmake.orig	2023-08-15 20:25:50.000000000 +0000
+++ cmake/QoreMacros.cmake
@@ -188,7 +188,9 @@ MACRO (QORE_BINARY_MODULE_INTERN2 _modul
     target_link_libraries(${_module_name} ${_libs})
 
     # ensure that modules use dynamic lookups; works with g++ & clang++
+    if(CMAKE_HOST_APPLE)
     set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -Wl,-undefined -Wl,dynamic_lookup")
+    endif(CMAKE_HOST_APPLE)
 
     install( TARGETS ${_module_name} DESTINATION ${_mod_target_dir})
 
