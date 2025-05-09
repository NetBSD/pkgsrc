$NetBSD: patch-lib_llvmopencl_FlattenGlobals.cc,v 1.1 2025/05/09 06:05:18 adam Exp $

Support LLVM 19.

--- lib/llvmopencl/FlattenGlobals.cc.orig	2025-05-03 06:29:36.030212660 +0000
+++ lib/llvmopencl/FlattenGlobals.cc
@@ -111,7 +111,7 @@ static bool flattenGlobals(Module &M) {
     llvm::Function *f = &*i;
     if (f->isDeclaration())
       continue;
-    if (f->getName().equals(barrier)) {
+    if (f->getName() == barrier) {
       f->removeFnAttr(Attribute::NoInline);
       f->removeFnAttr(Attribute::OptimizeNone);
       f->addFnAttr(Attribute::AlwaysInline);
