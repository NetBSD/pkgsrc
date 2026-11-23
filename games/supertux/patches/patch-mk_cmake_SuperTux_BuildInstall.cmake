$NetBSD: patch-mk_cmake_SuperTux_BuildInstall.cmake,v 1.2 2026/11/23 11:41:36 adam Exp $

On Darwin, don't use app bundle.

TARGETS RUNTIME_DEPENDENCY_SET is not supported on system "NetBSD".

--- mk/cmake/SuperTux/BuildInstall.cmake.orig	2026-11-22 04:50:58.000000000 +0000
+++ mk/cmake/SuperTux/BuildInstall.cmake
@@ -22,7 +22,7 @@ if(WIN32 AND NOT UNIX)
   endif()
 
 else()
-  if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin" AND DISABLE_CPACK_BUNDLING)
+  if(FALSE)
 
     set(INFOPLIST_CFBUNDLEEXECUTABLE "supertux2")
 
@@ -63,12 +63,12 @@ if(WIN32 AND CMAKE_HOST_WIN32)
 else()
   install(TARGETS supertux2
           DESTINATION ${INSTALL_SUBDIR_BIN}
-          RUNTIME_DEPENDENCY_SET supertux2_deps)
+          )
   if(NOT USE_STATIC_SIMPLESQUIRREL)
     if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin" AND NOT DISABLE_CPACK_BUNDLING)
       install(TARGETS simplesquirrel RUNTIME_DEPENDENCY_SET supertux2_deps LIBRARY DESTINATION "MacOS")
     else()
-      install(TARGETS simplesquirrel RUNTIME_DEPENDENCY_SET supertux2_deps)
+      install(TARGETS simplesquirrel)
     endif()
   endif()
 endif()
