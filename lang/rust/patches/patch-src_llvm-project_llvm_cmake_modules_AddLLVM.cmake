$NetBSD: patch-src_llvm-project_llvm_cmake_modules_AddLLVM.cmake,v 1.14 2023/10/25 05:50:43 pin Exp $

On Darwin, use correct install-name for shared libraries.

Undo some of the RPATH magic so that cross-building
works inside pkgsrc again (indirectly eliminates $ORIGIN rpath
handling / editing, $ORIGIN handling is partially undone by cwrappers
in pkgsrc).

--- src/llvm-project/llvm/cmake/modules/AddLLVM.cmake.orig	2023-07-12 03:33:01.000000000 +0000
+++ src/llvm-project/llvm/cmake/modules/AddLLVM.cmake
@@ -2311,7 +2311,7 @@ function(llvm_setup_rpath name)
   endif()
 
   if (APPLE)
-    set(_install_name_dir INSTALL_NAME_DIR "@rpath")
+    set(_install_name_dir INSTALL_NAME_DIR "${CMAKE_INSTALL_PREFIX}/lib")
     set(_install_rpath "@loader_path/../lib${LLVM_LIBDIR_SUFFIX}" ${extra_libdir})
   elseif(${CMAKE_SYSTEM_NAME} MATCHES "AIX" AND BUILD_SHARED_LIBS)
     # $ORIGIN is not interpreted at link time by aix ld.
@@ -2320,8 +2320,7 @@ function(llvm_setup_rpath name)
     # FIXME: update this when there is better solution.
     set(_install_rpath "${LLVM_LIBRARY_OUTPUT_INTDIR}" "${CMAKE_INSTALL_PREFIX}/lib${LLVM_LIBDIR_SUFFIX}" ${extra_libdir})
   elseif(UNIX)
-    set(_build_rpath "\$ORIGIN/../lib${LLVM_LIBDIR_SUFFIX}" ${extra_libdir})
-    set(_install_rpath "\$ORIGIN/../lib${LLVM_LIBDIR_SUFFIX}")
+    set(_install_rpath "\$ORIGIN/../lib${LLVM_LIBDIR_SUFFIX}" ${extra_libdir})
     if(${CMAKE_SYSTEM_NAME} MATCHES "(FreeBSD|DragonFly)")
       set_property(TARGET ${name} APPEND_STRING PROPERTY
                    LINK_FLAGS " -Wl,-z,origin ")
@@ -2335,16 +2334,9 @@ function(llvm_setup_rpath name)
     return()
   endif()
 
-  # Enable BUILD_WITH_INSTALL_RPATH unless CMAKE_BUILD_RPATH is set and not
-  # building for macOS or AIX, as those platforms seemingly require it.
-  # On AIX, the tool chain doesn't support modifying rpaths/libpaths for XCOFF
-  # on install at the moment, so BUILD_WITH_INSTALL_RPATH is required.
+  # Enable BUILD_WITH_INSTALL_RPATH unless CMAKE_BUILD_RPATH is set.
   if("${CMAKE_BUILD_RPATH}" STREQUAL "")
-    if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin|AIX")
-      set_property(TARGET ${name} PROPERTY BUILD_WITH_INSTALL_RPATH ON)
-    else()
-      set_property(TARGET ${name} APPEND PROPERTY BUILD_RPATH "${_build_rpath}")
-    endif()
+    set_property(TARGET ${name} PROPERTY BUILD_WITH_INSTALL_RPATH ON)
   endif()
 
   set_target_properties(${name} PROPERTIES
