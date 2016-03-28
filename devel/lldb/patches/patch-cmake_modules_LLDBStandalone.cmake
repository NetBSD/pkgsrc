$NetBSD: patch-cmake_modules_LLDBStandalone.cmake,v 1.1 2016/03/28 13:13:55 kamil Exp $

--- cmake/modules/LLDBStandalone.cmake.orig	2015-11-10 18:09:14.000000000 +0000
+++ cmake/modules/LLDBStandalone.cmake
@@ -6,57 +6,78 @@ if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURR
 
   option(LLVM_INSTALL_TOOLCHAIN_ONLY "Only include toolchain files in the 'install' target." OFF)
 
-  set(LLDB_PATH_TO_LLVM_SOURCE "" CACHE PATH
-    "Path to LLVM source code. Not necessary if using an installed LLVM.")
-  set(LLDB_PATH_TO_LLVM_BUILD "" CACHE PATH
-    "Path to the directory where LLVM was built or installed.")
-
-  set(LLDB_PATH_TO_CLANG_SOURCE "" CACHE PATH
-    "Path to Clang source code. Not necessary if using an installed Clang.")
-  set(LLDB_PATH_TO_CLANG_BUILD "" CACHE PATH
-    "Path to the directory where Clang was built or installed.")
-
-  if (LLDB_PATH_TO_LLVM_SOURCE)
-    if (NOT EXISTS "${LLDB_PATH_TO_LLVM_SOURCE}/cmake/config-ix.cmake")
-      message(FATAL_ERROR "Please set LLDB_PATH_TO_LLVM_SOURCE to the root "
-              "directory of LLVM source code.")
+  # Rely on llvm-config.
+  set(CONFIG_OUTPUT)
+  find_program(LLVM_CONFIG "llvm-config")
+  if(LLVM_CONFIG)
+    message(STATUS "Found LLVM_CONFIG as ${LLVM_CONFIG}")
+    set(CONFIG_COMMAND ${LLVM_CONFIG}
+      "--assertion-mode"
+      "--bindir"
+      "--libdir"
+      "--includedir"
+      "--prefix"
+      "--src-root")
+    execute_process(
+      COMMAND ${CONFIG_COMMAND}
+      RESULT_VARIABLE HAD_ERROR
+      OUTPUT_VARIABLE CONFIG_OUTPUT
+    )
+    if(NOT HAD_ERROR)
+      string(REGEX REPLACE
+        "[ \t]*[\r\n]+[ \t]*" ";"
+        CONFIG_OUTPUT ${CONFIG_OUTPUT})
+
     else()
-      get_filename_component(LLVM_MAIN_SRC_DIR ${LLDB_PATH_TO_LLVM_SOURCE}
-                             ABSOLUTE)
-      set(LLVM_MAIN_INCLUDE_DIR "${LLVM_MAIN_SRC_DIR}/include")
-      list(APPEND CMAKE_MODULE_PATH "${LLVM_MAIN_SRC_DIR}/cmake/modules")
+      string(REPLACE ";" " " CONFIG_COMMAND_STR "${CONFIG_COMMAND}")
+      message(STATUS "${CONFIG_COMMAND_STR}")
+      message(FATAL_ERROR "llvm-config failed with status ${HAD_ERROR}")
     endif()
-  endif()
-
-  if (LLDB_PATH_TO_CLANG_SOURCE)
-      get_filename_component(CLANG_MAIN_SRC_DIR ${LLDB_PATH_TO_CLANG_SOURCE}
-                             ABSOLUTE)
-      set(CLANG_MAIN_INCLUDE_DIR "${CLANG_MAIN_SRC_DIR}/include")
-  endif()
-
-  list(APPEND CMAKE_MODULE_PATH "${LLDB_PATH_TO_LLVM_BUILD}/share/llvm/cmake")
-
-  if (LLDB_PATH_TO_LLVM_BUILD)
-    get_filename_component(PATH_TO_LLVM_BUILD ${LLDB_PATH_TO_LLVM_BUILD}
-                           ABSOLUTE)
   else()
-    message(FATAL_ERROR "Please set LLDB_PATH_TO_LLVM_BUILD to the root "
-            "directory of LLVM build or install site.")
+    message(FATAL_ERROR "llvm-config not found -- ${LLVM_CONFIG}")
   endif()
 
-  if (LLDB_PATH_TO_CLANG_BUILD)
-    get_filename_component(PATH_TO_CLANG_BUILD ${LLDB_PATH_TO_CLANG_BUILD}
-                           ABSOLUTE)
+  list(GET CONFIG_OUTPUT 0 ENABLE_ASSERTIONS)
+  list(GET CONFIG_OUTPUT 1 TOOLS_BINARY_DIR)
+  list(GET CONFIG_OUTPUT 2 LIBRARY_DIR)
+  list(GET CONFIG_OUTPUT 3 INCLUDE_DIR)
+  list(GET CONFIG_OUTPUT 4 LLVM_OBJ_ROOT)
+  list(GET CONFIG_OUTPUT 5 MAIN_SRC_DIR)
+
+  if(NOT MSVC_IDE)
+    set(LLVM_ENABLE_ASSERTIONS ${ENABLE_ASSERTIONS}
+      CACHE BOOL "Enable assertions")
+    # Assertions should follow llvm-config's.
+    mark_as_advanced(LLVM_ENABLE_ASSERTIONS)
+  endif()
+
+  set(LLVM_TOOLS_BINARY_DIR ${TOOLS_BINARY_DIR} CACHE PATH "Path to llvm/bin")
+  set(LLVM_LIBRARY_DIR ${LIBRARY_DIR} CACHE PATH "Path to llvm/lib")
+  set(LLVM_MAIN_INCLUDE_DIR ${INCLUDE_DIR} CACHE PATH "Path to llvm/include")
+  set(LLVM_BINARY_DIR ${LLVM_OBJ_ROOT} CACHE PATH "Path to LLVM build tree")
+  set(LLVM_MAIN_SRC_DIR ${MAIN_SRC_DIR} CACHE PATH "Path to LLVM source tree")
+
+  find_program(LLVM_TABLEGEN_EXE "llvm-tblgen" ${LLVM_TOOLS_BINARY_DIR}
+    NO_DEFAULT_PATH)
+
+  set(LLVM_CMAKE_PATH "${LLVM_BINARY_DIR}/share/llvm/cmake") # this will change in 3.9.0
+  set(LLVMCONFIG_FILE "${LLVM_CMAKE_PATH}/LLVMConfig.cmake")
+  if(EXISTS ${LLVMCONFIG_FILE})
+    list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_PATH}")
+    include(${LLVMCONFIG_FILE})
   else()
-    message(FATAL_ERROR "Please set LLDB_PATH_TO_CLANG_BUILD to the root "
-            "directory of Clang build or install site.")
+    message(FATAL_ERROR "Not found: ${LLVMCONFIG_FILE}")
   endif()
 
-
-  # These variables are used by add_llvm_library.
+  # They are used as destination of target generators.
   set(LLVM_RUNTIME_OUTPUT_INTDIR ${CMAKE_BINARY_DIR}/${CMAKE_CFG_INTDIR}/bin)
   set(LLVM_LIBRARY_OUTPUT_INTDIR ${CMAKE_BINARY_DIR}/${CMAKE_CFG_INTDIR}/lib${LLVM_LIBDIR_SUFFIX})
-  set(LLVM_LIBRARY_DIR ${LLVM_LIBRARY_OUTPUT_INTDIR})
+  if(WIN32 OR CYGWIN)
+    # DLL platform -- put DLLs into bin.
+    set(LLVM_SHLIB_OUTPUT_INTDIR ${LLVM_RUNTIME_OUTPUT_INTDIR})
+  else()
+    set(LLVM_SHLIB_OUTPUT_INTDIR ${LLVM_LIBRARY_OUTPUT_INTDIR})
+  endif()
 
   include(AddLLVM)
   include(HandleLLVMOptions)
@@ -73,23 +94,16 @@ if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURR
     message("-- Found PythonInterp: ${PYTHON_EXECUTABLE}")
   endif()
   # Import CMake library targets from LLVM and Clang.
-  include("${LLDB_PATH_TO_LLVM_BUILD}/share/llvm/cmake/LLVMConfig.cmake")
-  if (EXISTS "${LLDB_PATH_TO_CLANG_BUILD}/share/clang/cmake/ClangConfig.cmake")
-      include("${LLDB_PATH_TO_CLANG_BUILD}/share/clang/cmake/ClangConfig.cmake")
-  endif()
+  include("${LLVM_OBJ_ROOT}/share/llvm/cmake/LLVMConfig.cmake") # this will change in 3.9.0
+  include("${LLVM_OBJ_ROOT}/share/clang/cmake/ClangConfig.cmake") # this will change in 3.9.0
 
   set(PACKAGE_VERSION "${LLVM_PACKAGE_VERSION}")
 
   set(LLVM_BINARY_DIR ${CMAKE_BINARY_DIR})
 
   set(CMAKE_INCLUDE_CURRENT_DIR ON)
-  include_directories("${PATH_TO_LLVM_BUILD}/include"
-                      "${LLVM_MAIN_INCLUDE_DIR}"
-                      "${PATH_TO_CLANG_BUILD}/include"
-                      "${CLANG_MAIN_INCLUDE_DIR}"
-                      "${CMAKE_CURRENT_SOURCE_DIR}/source")
-  link_directories("${PATH_TO_LLVM_BUILD}/lib${LLVM_LIBDIR_SUFFIX}"
-                   "${PATH_TO_CLANG_BUILD}/lib${LLVM_LIBDIR_SUFFIX}")
+  include_directories("${LLVM_BINARY_DIR}/include" "${LLVM_MAIN_INCLUDE_DIR}")
+  link_directories("${LLVM_LIBRARY_DIR}")
 
   set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
   set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib${LLVM_LIBDIR_SUFFIX})
