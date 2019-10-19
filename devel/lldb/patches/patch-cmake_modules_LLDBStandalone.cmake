$NetBSD: patch-cmake_modules_LLDBStandalone.cmake,v 1.4 2019/10/19 14:01:37 adam Exp $

--- cmake/modules/LLDBStandalone.cmake.orig	2019-07-17 19:36:20.000000000 +0000
+++ cmake/modules/LLDBStandalone.cmake
@@ -74,7 +74,6 @@ list(APPEND CMAKE_MODULE_PATH "${LLVM_DI
 include(AddLLVM)
 include(TableGen)
 include(HandleLLVMOptions)
-include(CheckAtomic)
 include(LLVMDistributionSupport)
 
 set(PACKAGE_VERSION "${LLVM_PACKAGE_VERSION}")
