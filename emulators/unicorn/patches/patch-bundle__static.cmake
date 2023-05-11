$NetBSD: patch-bundle__static.cmake,v 1.1 2023/05/11 06:47:11 adam Exp $

Use proper libtool on Darwin.

--- bundle_static.cmake.orig	2023-05-10 19:31:11.000000000 +0000
+++ bundle_static.cmake
@@ -44,14 +44,12 @@ function(bundle_static_library tgt_name 
     ${CMAKE_BINARY_DIR}/${CMAKE_STATIC_LIBRARY_PREFIX}${library_name}${CMAKE_STATIC_LIBRARY_SUFFIX})
   
   if (APPLE)
-    find_program(lib_tool libtool REQUIRED)
-
     foreach(tgt IN LISTS static_libs)
       list(APPEND static_libs_full_names $<TARGET_FILE:${tgt}>)
     endforeach()
 
     add_custom_command(
-      COMMAND ${lib_tool} -static -o ${bundled_tgt_full_name} ${static_libs_full_names}
+      COMMAND /usr/bin/libtool -static -o ${bundled_tgt_full_name} ${static_libs_full_names}
       OUTPUT ${bundled_tgt_full_name}
       COMMENT "Bundling ${bundled_tgt_name}"
       VERBATIM)
@@ -112,4 +110,4 @@ function(bundle_static_library tgt_name 
       #IMPORTED_LINK_INTERFACE_LIBRARIES "${dep_libs}") # Deprecated
   add_dependencies(${bundled_tgt_name} bundling_target)
 
-endfunction()
\ No newline at end of file
+endfunction()
