$NetBSD: patch-build_env.cmake,v 1.3 2025/02/02 14:25:34 bacon Exp $

# static standard libs are not standard nor easy to install on Alma Linux

--- build/env.cmake.orig	2025-01-29 20:24:37.167226512 +0000
+++ build/env.cmake
@@ -574,9 +574,7 @@ include(CheckCXXSourceRuns)
 
 if ( "GNU" STREQUAL "${CMAKE_C_COMPILER_ID}" )
     # check for the presence of static C/C++ runtime libraries
-    set(CMAKE_REQUIRED_LINK_OPTIONS -static-libgcc)
     check_cxx_source_runs("int main(int argc, char *argv[]) { return 0; }" HAVE_STATIC_LIBGCC)
-    set(CMAKE_REQUIRED_LINK_OPTIONS -static-libstdc++)
     check_cxx_source_runs("int main(int argc, char *argv[]) { return 0; }" HAVE_STATIC_LIBSTDCXX)
 endif()
 
@@ -584,10 +582,10 @@ function(MakeLinksExe target install_via
 
     if ( "GNU" STREQUAL "${CMAKE_C_COMPILER_ID}" )
         if ( HAVE_STATIC_LIBGCC )
-            target_link_options( ${target} PRIVATE -static-libgcc )
+            target_link_options( ${target} PRIVATE )
         endif()
         if ( HAVE_STATIC_LIBSTDCXX )
-            target_link_options( ${target} PRIVATE -static-libstdc++ )
+            target_link_options( ${target} PRIVATE )
         endif()
     endif()
 
