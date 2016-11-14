$NetBSD: patch-cmake_modules_TableGen.cmake,v 1.2 2016/11/14 20:15:33 ryoon Exp $

Disable install of llvm-tblgen, provided by lang/llvm.

--- cmake/modules/TableGen.cmake.orig	2016-06-08 21:19:26.000000000 +0000
+++ cmake/modules/TableGen.cmake
@@ -138,7 +138,7 @@ macro(add_tablegen target project)
       set_target_properties(${target} PROPERTIES LINK_FLAGS -Wl,--stack,16777216)
     endif(CMAKE_SIZEOF_VOID_P MATCHES "8")
   endif( MINGW )
-  if (${project} STREQUAL LLVM AND NOT LLVM_INSTALL_TOOLCHAIN_ONLY)
+  if (${project} STREQUAL LLVM AND NOT LLVM_INSTALL_TOOLCHAIN_ONLY AND false)
     install(TARGETS ${target}
             EXPORT LLVMExports
             RUNTIME DESTINATION ${LLVM_TOOLS_INSTALL_DIR})
