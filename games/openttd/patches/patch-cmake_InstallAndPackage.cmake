$NetBSD: patch-cmake_InstallAndPackage.cmake,v 1.4 2024/04/28 20:01:49 triaxx Exp $

Do not try to generate Linux distribution packages.

--- cmake/InstallAndPackage.cmake.orig	2023-06-11 16:42:59.000000000 +0000
+++ cmake/InstallAndPackage.cmake
@@ -152,7 +152,7 @@ set(CPACK_PACKAGE_EXECUTABLES "openttd;O
 set(CPACK_STRIP_FILES YES)
 set(CPACK_OUTPUT_FILE_PREFIX "bundles")
 
-if(APPLE)
+if(FALSE)
     # Stripping would produce unreadable stacktraces.
     set(CPACK_STRIP_FILES NO)
     set(CPACK_GENERATOR "Bundle")
@@ -185,10 +185,11 @@ elseif(UNIX)
     if(OPTION_PACKAGE_DEPENDENCIES)
         set(CPACK_GENERATOR "TXZ")
         set(PLATFORM "generic")
-    elseif(NOT OPTION_INSTALL_FHS)
+    else()
         set(CPACK_GENERATOR "TXZ")
         set(PLATFORM "unknown")
-    else()
+    endif()
+    if(FALSE)
         find_program(LSB_RELEASE_EXEC lsb_release)
         execute_process(COMMAND ${LSB_RELEASE_EXEC} -is
             OUTPUT_VARIABLE LSB_RELEASE_ID
