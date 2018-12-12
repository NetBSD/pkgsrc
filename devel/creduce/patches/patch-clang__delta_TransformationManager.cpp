$NetBSD: patch-clang__delta_TransformationManager.cpp,v 1.4 2018/12/12 12:44:43 adam Exp $

Fix for LLVM 7.0.
https://github.com/csmith-project/creduce/tree/llvm-7.0

--- clang_delta/TransformationManager.cpp.orig	2018-12-12 12:37:38.000000000 +0000
+++ clang_delta/TransformationManager.cpp
@@ -223,7 +223,7 @@ llvm::raw_ostream *TransformationManager
 
   std::error_code EC;
   llvm::raw_fd_ostream *Out = new llvm::raw_fd_ostream(
-      OutputFileName, EC, llvm::sys::fs::F_RW);
+      OutputFileName, EC, llvm::sys::fs::FA_Read | llvm::sys::fs::FA_Write);
   assert(!EC && "Cannot open output file!");
   return Out;
 }
