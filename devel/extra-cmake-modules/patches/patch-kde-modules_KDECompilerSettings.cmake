$NetBSD: patch-kde-modules_KDECompilerSettings.cmake,v 1.1 2016/06/07 17:54:59 joerg Exp $

Do not hard-code --enable-new-dtags. It is completely broken on systems like
NetBSD implementing the sane rpath semantic and just have a new enough binutils
version. It is up to the system compiler to know what the correct platfor
choice is.

--- kde-modules/KDECompilerSettings.cmake.orig	2016-06-05 23:16:56.900586724 +0000
+++ kde-modules/KDECompilerSettings.cmake
@@ -208,14 +208,6 @@ if (POLICY CMP0063)
     cmake_policy(SET CMP0063 NEW)
 endif()
 
-if (UNIX AND NOT APPLE)
-    # Enable adding DT_RUNPATH, which means that LD_LIBRARY_PATH takes precedence
-    # over the built-in rPath
-    set(CMAKE_SHARED_LINKER_FLAGS "-Wl,--enable-new-dtags ${CMAKE_SHARED_LINKER_FLAGS}")
-    set(CMAKE_MODULE_LINKER_FLAGS "-Wl,--enable-new-dtags ${CMAKE_MODULE_LINKER_FLAGS}")
-    set(CMAKE_EXE_LINKER_FLAGS    "-Wl,--enable-new-dtags ${CMAKE_EXE_LINKER_FLAGS}")
-endif()
-
 if (CMAKE_SYSTEM_NAME STREQUAL GNU)
     # Enable multithreading with the pthread library
     # FIXME: Is this actually necessary to have here?
