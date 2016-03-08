$NetBSD: patch-cmake_modules_TableGen.cmake,v 1.1 2016/03/08 21:06:50 tnn Exp $

Disable install of llvm-tblgen, provided by lang/llvm.

--- cmake/modules/TableGen.cmake.orig	2015-10-23 19:48:17.000000000 +0000
+++ cmake/modules/TableGen.cmake
@@ -138,7 +138,7 @@ macro(add_tablegen target project)
       set_target_properties(${target} PROPERTIES LINK_FLAGS -Wl,--stack,16777216)
     endif(CMAKE_SIZEOF_VOID_P MATCHES "8")
   endif( MINGW )
-  if (${project} STREQUAL LLVM AND NOT LLVM_INSTALL_TOOLCHAIN_ONLY)
+  if (${project} STREQUAL LLVM AND NOT LLVM_INSTALL_TOOLCHAIN_ONLY AND false)
     install(TARGETS ${target}
             EXPORT LLVMExports
             RUNTIME DESTINATION bin)
