$NetBSD: patch-build_env.cmake,v 1.1 2023/08/29 00:00:25 bacon Exp $

# static standard libs are not standard nor easy to install on Alma Linux

--- build/env.cmake.orig	2023-08-13 18:06:02.445968665 +0000
+++ build/env.cmake
@@ -555,7 +555,7 @@ endfunction()
 function(MakeLinksExe target install_via_driver)
 
     if ( "GNU" STREQUAL "${CMAKE_C_COMPILER_ID}" )
-        target_link_options( ${target} PRIVATE -static-libgcc -static-libstdc++ )
+        target_link_options( ${target} PRIVATE )
     endif()
 
 # creates dependency loops
