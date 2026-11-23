$NetBSD: patch-build_env.cmake,v 1.4 2026/11/23 08:07:34 wiz Exp $

static standard libs are not standard nor easy to install on Alma Linux

Fix build with cmake 4.5.

--- build/env.cmake.orig	2025-01-15 00:39:17.000000000 +0000
+++ build/env.cmake
@@ -574,9 +574,7 @@ if ( "GNU" STREQUAL "${CMAKE_C_COMPILER_ID}" )
 
 if ( "GNU" STREQUAL "${CMAKE_C_COMPILER_ID}" )
     # check for the presence of static C/C++ runtime libraries
-    set(CMAKE_REQUIRED_LINK_OPTIONS -static-libgcc)
     check_cxx_source_runs("int main(int argc, char *argv[]) { return 0; }" HAVE_STATIC_LIBGCC)
-    set(CMAKE_REQUIRED_LINK_OPTIONS -static-libstdc++)
     check_cxx_source_runs("int main(int argc, char *argv[]) { return 0; }" HAVE_STATIC_LIBSTDCXX)
 endif()
 
@@ -584,10 +582,10 @@ function(MakeLinksExe target install_via_driver)
 
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
 
@@ -731,7 +729,7 @@ if ( SINGLE_CONFIG )
     if ( BUILD_TOOLS_INTERNAL )
         set( VDB_COPY_DIR ${CMAKE_SOURCE_DIR}/tools/internal/vdb-copy )
     endif()
-    install( SCRIPT CODE
+    install( CODE
         "execute_process( COMMAND /bin/sh -c        \
             \"${CMAKE_SOURCE_DIR}/build/install.sh  \
                 ${VDB_INCDIR}/kfg/ncbi              \
