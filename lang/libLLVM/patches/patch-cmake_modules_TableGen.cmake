$NetBSD: patch-cmake_modules_TableGen.cmake,v 1.3 2017/03/17 22:38:18 adam Exp $

Disable install of llvm-tblgen, provided by lang/llvm.

--- cmake/modules/TableGen.cmake.orig	2016-12-06 17:09:29.000000000 +0000
+++ cmake/modules/TableGen.cmake
@@ -134,7 +134,7 @@ macro(add_tablegen target project)
     endif()
   endif()
 
-  if (${project} STREQUAL LLVM AND NOT LLVM_INSTALL_TOOLCHAIN_ONLY)
+  if (${project} STREQUAL LLVM AND NOT LLVM_INSTALL_TOOLCHAIN_ONLY AND false)
     if(${target} IN_LIST LLVM_DISTRIBUTION_COMPONENTS OR
         NOT LLVM_DISTRIBUTION_COMPONENTS)
       set(export_to_llvmexports EXPORT LLVMExports)
