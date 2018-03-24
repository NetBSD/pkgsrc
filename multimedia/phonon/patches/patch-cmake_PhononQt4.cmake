$NetBSD: patch-cmake_PhononQt4.cmake,v 1.1 2018/03/24 17:07:53 joerg Exp $

--- cmake/PhononQt4.cmake.orig	2018-03-23 23:44:05.722447056 +0000
+++ cmake/PhononQt4.cmake
@@ -196,7 +196,7 @@ if (CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_C_FLAGS_DEBUGFULL        "-g3 -fno-inline")
    set(CMAKE_C_FLAGS_PROFILE          "-g3 -fno-inline -ftest-coverage -fprofile-arcs")
 
-   set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -Wno-long-long -std=iso9899:1990 -Wundef -Wcast-align -Werror-implicit-function-declaration -Wchar-subscripts -Wall -W -Wpointer-arith -Wwrite-strings -Wformat-security -Wmissing-format-attribute -fno-common")
+   set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -Wno-long-long -Wundef -Wcast-align -Werror-implicit-function-declaration -Wchar-subscripts -Wall -W -Wpointer-arith -Wwrite-strings -Wformat-security -Wmissing-format-attribute -fno-common")
    # As of Qt 4.6.x we need to override the new exception macros if we want compile with -fno-exceptions
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wnon-virtual-dtor -Wno-long-long -Wundef -Wcast-align -Wchar-subscripts -Wall -W -Wpointer-arith -Wformat-security -fno-exceptions -DQT_NO_EXCEPTIONS -fno-check-new -fno-common")
 
@@ -318,7 +318,7 @@ if (CMAKE_CXX_COMPILER_ID STREQUAL "Clan
    set(CMAKE_C_FLAGS_DEBUGFULL        "-g3 -fno-inline")
    set(CMAKE_C_FLAGS_PROFILE          "-g3 -fno-inline -ftest-coverage -fprofile-arcs")
 
-   set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -Wno-long-long -std=iso9899:1990 -Wundef -Wcast-align -Werror-implicit-function-declaration -Wchar-subscripts -Wall -W -Wpointer-arith -Wwrite-strings -Wformat-security -Wmissing-format-attribute -fno-common")
+   set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -Wno-long-long -Wundef -Wcast-align -Werror-implicit-function-declaration -Wchar-subscripts -Wall -W -Wpointer-arith -Wwrite-strings -Wformat-security -Wmissing-format-attribute -fno-common")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wnon-virtual-dtor -Wno-long-long -Wundef -Wcast-align -Wchar-subscripts -Wall -W -Wpointer-arith -Wformat-security -Woverloaded-virtual -fno-common -fvisibility=hidden -Werror=return-type -fvisibility-inlines-hidden")
    set(KDE4_C_FLAGS    "-fvisibility=hidden")
 
