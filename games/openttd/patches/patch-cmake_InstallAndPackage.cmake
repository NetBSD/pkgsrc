$NetBSD: patch-cmake_InstallAndPackage.cmake,v 1.1 2021/05/04 17:08:05 nia Exp $

Do not try to generate Linux distribution packages.

--- cmake/InstallAndPackage.cmake.orig	2021-05-03 18:41:45.000000000 +0000
+++ cmake/InstallAndPackage.cmake
@@ -145,47 +145,9 @@ elseif(UNIX)
     if(OPTION_PACKAGE_DEPENDENCIES)
         set(CPACK_GENERATOR "TXZ")
         set(PLATFORM "generic")
-    elseif(NOT OPTION_INSTALL_FHS)
+    else()
         set(CPACK_GENERATOR "TXZ")
         set(PLATFORM "unknown")
-    else()
-        find_program(LSB_RELEASE_EXEC lsb_release)
-        execute_process(COMMAND ${LSB_RELEASE_EXEC} -is
-            OUTPUT_VARIABLE LSB_RELEASE_ID
-            OUTPUT_STRIP_TRAILING_WHITESPACE
-        )
-        if(LSB_RELEASE_ID)
-            if(LSB_RELEASE_ID STREQUAL "Ubuntu" OR LSB_RELEASE_ID STREQUAL "Debian")
-                execute_process(COMMAND ${LSB_RELEASE_EXEC} -cs
-                    OUTPUT_VARIABLE LSB_RELEASE_CODENAME
-                    OUTPUT_STRIP_TRAILING_WHITESPACE
-                )
-                string(TOLOWER "${LSB_RELEASE_ID}-${LSB_RELEASE_CODENAME}" PLATFORM)
-
-                set(CPACK_GENERATOR "DEB")
-                include(PackageDeb)
-            else()
-                set(UNSUPPORTED_PLATFORM_NAME "LSB-based Linux distribution '${LSB_RELEASE_ID}'")
-            endif()
-        elseif(EXISTS "/etc/os-release")
-            file(STRINGS "/etc/os-release" OS_RELEASE_CONTENTS REGEX "^ID=")
-            string(REGEX MATCH "ID=(.*)" _ ${OS_RELEASE_CONTENTS})
-            set(DISTRO_ID ${CMAKE_MATCH_1})
-            if(DISTRO_ID STREQUAL "arch")
-                set(PLATFORM "arch")
-                set(CPACK_GENERATOR "TXZ")
-            else()
-                set(UNSUPPORTED_PLATFORM_NAME "Linux distribution '${DISTRO_ID}' from /etc/os-release")
-            endif()
-        else()
-            set(UNSUPPORTED_PLATFORM_NAME "Linux distribution")
-        endif()
-
-        if(NOT PLATFORM)
-            set(PLATFORM "generic")
-            set(CPACK_GENERATOR "TXZ")
-            message(WARNING "Unknown ${UNSUPPORTED_PLATFORM_NAME} found for packaging; can only pack to a txz. Please consider creating a Pull Request to add support for this distribution.")
-        endif()
     endif()
 
     set(CPACK_PACKAGE_FILE_NAME "openttd-#CPACK_PACKAGE_VERSION#-linux-${PLATFORM}-${CPACK_SYSTEM_NAME}")
