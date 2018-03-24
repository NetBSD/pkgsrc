$NetBSD: patch-kde-modules_KDECompilerSettings.cmake,v 1.3 2018/03/24 20:13:40 joerg Exp $

Do not hard-code --enable-new-dtags. It is completely broken on systems like
NetBSD implementing the sane rpath semantic and just have a new enough binutils
version. It is up to the system compiler to know what the correct platfor
choice is.

Do not force C90 mode. It is not a reasonable default.

--- kde-modules/KDECompilerSettings.cmake.orig	2017-11-30 07:42:14.000000000 +0000
+++ kde-modules/KDECompilerSettings.cmake
@@ -189,11 +189,6 @@ endif()
 # Pick sensible versions of the C and C++ standards.
 # Note that MSVC does not have equivalent flags; the features are either
 # supported or they are not.
-if (CMAKE_C_COMPILER_ID STREQUAL "GNU" OR CMAKE_C_COMPILER_ID MATCHES "Clang")
-    # We use the C89 standard because that is what is common to all our
-    # compilers (in particular, MSVC 2010 does not support C99)
-    set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -std=iso9899:1990")
-endif()
 if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
 elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel" AND NOT WIN32)
@@ -229,14 +224,6 @@ if (POLICY CMP0063)
     cmake_policy(SET CMP0063 NEW)
 endif()
 
-if (UNIX AND NOT APPLE AND NOT CYGWIN)
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
