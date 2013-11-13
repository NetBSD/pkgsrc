$NetBSD: patch-cmake_FindPhononInternal.cmake,v 1.1 2013/11/13 22:51:06 joerg Exp $

--- cmake/FindPhononInternal.cmake.orig	2013-11-13 13:44:42.000000000 +0000
+++ cmake/FindPhononInternal.cmake
@@ -320,16 +320,16 @@ if (CMAKE_COMPILER_IS_GNUCXX)
    # Select flags.
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g -DNDEBUG -DQT_NO_DEBUG")
    set(CMAKE_CXX_FLAGS_RELEASE        "-O2 -DNDEBUG -DQT_NO_DEBUG")
-   set(CMAKE_CXX_FLAGS_DEBUG          "-g -O2 -fno-reorder-blocks -fno-schedule-insns -fno-inline")
+   set(CMAKE_CXX_FLAGS_DEBUG          "-g -O2 -fno-inline")
    set(CMAKE_CXX_FLAGS_DEBUGFULL      "-g3 -fno-inline")
    set(CMAKE_CXX_FLAGS_PROFILE        "-g3 -fno-inline -ftest-coverage -fprofile-arcs")
    set(CMAKE_C_FLAGS_RELWITHDEBINFO   "-O2 -g -DNDEBUG -DQT_NO_DEBUG")
    set(CMAKE_C_FLAGS_RELEASE          "-O2 -DNDEBUG -DQT_NO_DEBUG")
-   set(CMAKE_C_FLAGS_DEBUG            "-g -O2 -fno-reorder-blocks -fno-schedule-insns -fno-inline")
+   set(CMAKE_C_FLAGS_DEBUG            "-g -O2 -fno-inline")
    set(CMAKE_C_FLAGS_DEBUGFULL        "-g3 -fno-inline")
    set(CMAKE_C_FLAGS_PROFILE          "-g3 -fno-inline -ftest-coverage -fprofile-arcs")
 
-   set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -Wno-long-long -std=iso9899:1990 -Wundef -Wcast-align -Werror-implicit-function-declaration -Wchar-subscripts -Wall -W -Wpointer-arith -Wwrite-strings -Wformat-security -Wmissing-format-attribute -fno-common")
+   set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -Wno-long-long -Wundef -Wcast-align -Werror-implicit-function-declaration -Wchar-subscripts -Wall -W -Wpointer-arith -Wwrite-strings -Wformat-security -Wmissing-format-attribute -fno-common")
    # As of Qt 4.6.x we need to override the new exception macros if we want compile with -fno-exceptions
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wnon-virtual-dtor -Wno-long-long -Wundef -Wcast-align -Wchar-subscripts -Wall -W -Wpointer-arith -Wformat-security -fno-exceptions -DQT_NO_EXCEPTIONS -fno-check-new -fno-common")
 
