$NetBSD: patch-lib_llvmopencl_Flatten.cc,v 1.1 2025/05/09 06:05:18 adam Exp $

Support LLVM 19.

--- lib/llvmopencl/Flatten.cc.orig	2025-05-03 06:33:52.040026650 +0000
+++ lib/llvmopencl/Flatten.cc
@@ -74,7 +74,7 @@ static bool flattenAll(Module &M) {

   for (llvm::Module::iterator i = M.begin(), e = M.end(); i != e; ++i) {
     llvm::Function *f = &*i;
-    if (f->isDeclaration() || f->getName().startswith("__pocl_print") ||
+    if (f->isDeclaration() || f->getName().starts_with("__pocl_print") ||
         AuxFuncs.find(f->getName().str()) != AuxFuncs.end())
       continue;
