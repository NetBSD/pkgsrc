$NetBSD: patch-lib_llvmopencl_MinLegalVecSize.cc,v 1.1 2025/05/09 06:05:18 adam Exp $

Support LLVM 19.

--- lib/llvmopencl/MinLegalVecSize.cc.orig	2025-05-03 06:41:11.677977719 +0000
+++ lib/llvmopencl/MinLegalVecSize.cc
@@ -133,7 +133,7 @@ static uint64_t getAndFixLargestVecSize(
       if (Callee == nullptr)
         continue;

-      if (Callee->hasName() && Callee->getName().startswith("llvm."))
+      if (Callee->hasName() && Callee->getName().starts_with("llvm."))
         continue;

       Calls.push_back(Callee);
@@ -188,7 +188,7 @@ static bool fixMinVecSize(Module &M) {
     llvm::Function *F = &*i;
     if (F->isDeclaration())
       continue;
-    if (F->hasName() && F->getName().startswith("llvm."))
+    if (F->hasName() && F->getName().starts_with("llvm."))
       continue;

     // AttributeSet Attrs;
@@ -219,7 +219,7 @@ static bool fixMinVecSize(Module &M) {
     llvm::Function *F = &*i;
     if (F->isDeclaration())
       continue;
-    if (F->hasName() && F->getName().startswith("llvm."))
+    if (F->hasName() && F->getName().starts_with("llvm."))
       continue;
     if (pocl::isKernelToProcess(*F))
       continue;
