$NetBSD: patch-lib_llvmopencl_FlattenBarrierSubs.cc,v 1.1 2025/05/09 06:05:18 adam Exp $

Support LLVM 19.

--- lib/llvmopencl/FlattenBarrierSubs.cc.orig	2025-05-03 06:34:58.933958001 +0000
+++ lib/llvmopencl/FlattenBarrierSubs.cc
@@ -71,7 +71,7 @@ static bool recursivelyInlineBarrierUser
       CallInst *CallInstr = dyn_cast<CallInst>(Instr);
       Function *Callee = CallInstr->getCalledFunction();

-      if ((Callee == nullptr) ||  Callee->getName().startswith("llvm."))
+      if ((Callee == nullptr) ||  Callee->getName().starts_with("llvm."))
         continue;

       if (llvm::isa<pocl::Barrier>(CallInstr))
