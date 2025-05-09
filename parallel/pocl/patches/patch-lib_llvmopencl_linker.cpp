$NetBSD: patch-lib_llvmopencl_linker.cpp,v 1.1 2025/05/09 06:05:19 adam Exp $

Support LLVM 19.

--- lib/llvmopencl/linker.cpp.orig	2025-05-03 06:36:30.822749420 +0000
+++ lib/llvmopencl/linker.cpp
@@ -121,7 +121,7 @@ static void fixCallingConv(llvm::Module
         CallInst *CallInstr = dyn_cast<CallInst>(Instr);
         Function *Callee = CallInstr->getCalledFunction();

-        if ((Callee == nullptr) || Callee->getName().startswith("llvm.") ||
+        if ((Callee == nullptr) || Callee->getName().starts_with("llvm.") ||
             Callee->isDeclaration())
           continue;

@@ -434,9 +434,9 @@ int link(llvm::Module *Program, const ll
       if (copy_func_callgraph(r, Lib, Program, vvm)) {
         Function *f = Program->getFunction(r);

-        if (f->getName().equals("__to_local") ||
-            f->getName().equals("__to_global") ||
-            f->getName().equals("__to_private")) {
+        if (f->getName() == "__to_local" ||
+            f->getName() == "__to_global" ||
+            f->getName() == "__to_private") {

           // Special handling for the AS cast built-ins: They do not use
           // type mangling, which complicates the CPU implementation which
@@ -478,9 +478,9 @@ int link(llvm::Module *Program, const ll
             (f->isDeclaration() &&
              // A target might want to expose the C99 printf in case not supporting
              // the OpenCL 1.2 printf.
-             !f->getName().equals("printf") &&
-             !f->getName().equals(pocl_sampler_handler) &&
-             !f->getName().startswith(llvm_intrins))
+             f->getName() != "printf" &&
+             f->getName() != pocl_sampler_handler &&
+             !f->getName().starts_with(llvm_intrins))
            ) {
           Log.append("Cannot find symbol ");
           Log.append(r.str());
