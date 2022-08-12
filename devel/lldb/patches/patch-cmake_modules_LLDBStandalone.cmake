$NetBSD: patch-cmake_modules_LLDBStandalone.cmake,v 1.5 2022/08/12 08:54:31 pin Exp $

--- cmake/modules/LLDBStandalone.cmake.orig	2022-06-22 16:46:24.000000000 +0000
+++ cmake/modules/LLDBStandalone.cmake
@@ -85,7 +85,6 @@ list(APPEND CMAKE_MODULE_PATH "${LLVM_DI
 include(AddLLVM)
 include(TableGen)
 include(HandleLLVMOptions)
-include(CheckAtomic)
 include(LLVMDistributionSupport)
 
 set(PACKAGE_VERSION "${LLVM_PACKAGE_VERSION}")
