$NetBSD: patch-cmake_FindPhononInternal.cmake,v 1.3 2016/03/01 08:54:42 markd Exp $

Disable Darwin section, creates unusable libraries.
_include_dirs fix for qt-5.4.2

--- cmake/FindPhononInternal.cmake.orig	2014-12-04 09:30:26.000000000 +0000
+++ cmake/FindPhononInternal.cmake
@@ -199,14 +199,14 @@ set(INSTALL_TARGETS_DEFAULT_ARGS RUNTIME
                                  ARCHIVE DESTINATION "${LIB_INSTALL_DIR}" COMPONENT Devel)
 
 # on the Mac support an extra install directory for application bundles
-if(APPLE)
+if(notAPPLE)
     set(INSTALL_TARGETS_DEFAULT_ARGS ${INSTALL_TARGETS_DEFAULT_ARGS}
                                      BUNDLE DESTINATION "${BUNDLE_INSTALL_DIR}")
     set(CMAKE_SHARED_MODULE_CREATE_C_FLAGS   "${CMAKE_SHARED_MODULE_CREATE_C_FLAGS}   -flat_namespace -undefined dynamic_lookup")
     set(CMAKE_SHARED_MODULE_CREATE_CXX_FLAGS "${CMAKE_SHARED_MODULE_CREATE_CXX_FLAGS} -flat_namespace -undefined dynamic_lookup")
 
    set(CMAKE_INSTALL_NAME_DIR ${LIB_INSTALL_DIR})
-endif(APPLE)
+endif(notAPPLE)
 
 # RPATH Handling
 
@@ -324,16 +324,16 @@ if (CMAKE_COMPILER_IS_GNUCXX)
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
 
@@ -409,7 +409,7 @@ if (CMAKE_COMPILER_IS_GNUCXX)
       file(WRITE "${_source_file}" "${_source}")
       set(_include_dirs "-DINCLUDE_DIRECTORIES:STRING=${QT_INCLUDES}")
 
-      try_compile(_compile_result ${CMAKE_BINARY_DIR} ${_source_file} CMAKE_FLAGS "${_include_dirs}" OUTPUT_VARIABLE _compile_output_var)
+      try_compile(_compile_result ${CMAKE_BINARY_DIR} ${_source_file} CMAKE_FLAGS "${CMAKE_CXX_FLAGS}" COMPILE_DEFINITIONS "${_include_dirs}" OUTPUT_VARIABLE _compile_output_var)
 
       if(NOT _compile_result)
          message("${_compile_output_var}")
