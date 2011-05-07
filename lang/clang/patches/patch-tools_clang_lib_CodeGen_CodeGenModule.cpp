$NetBSD: patch-tools_clang_lib_CodeGen_CodeGenModule.cpp,v 1.1 2011/05/07 16:54:56 adam Exp $

Fix LLVM bug 8765: longjmp issue on NetBSD.

--- tools/clang/lib/CodeGen/CodeGenModule.cpp.orig	2011-05-05 06:23:06.000000000 +0000
+++ tools/clang/lib/CodeGen/CodeGenModule.cpp
@@ -1561,14 +1561,24 @@
          "isn't a lib fn");
 
   // Get the name, skip over the __builtin_ prefix (if necessary).
-  const char *Name = Context.BuiltinInfo.GetName(BuiltinID);
-  if (Context.BuiltinInfo.isLibFunction(BuiltinID))
-    Name += 10;
+  llvm::StringRef Name;
+  GlobalDecl D(FD);
 
+  // If the builtin has been declared explicitly with an assembler label,
+  // use the mangled name. This differs from the plain label on platforms
+  // that prefix labels.
+  if (FD->hasAttr<AsmLabelAttr>())
+    Name = getMangledName(D);
+  else if (Context.BuiltinInfo.isLibFunction(BuiltinID))
+    Name = Context.BuiltinInfo.GetName(BuiltinID) + 10;
+  else
+    Name = Context.BuiltinInfo.GetName(BuiltinID);
+
+
   const llvm::FunctionType *Ty =
     cast<llvm::FunctionType>(getTypes().ConvertType(FD->getType()));
 
-  return GetOrCreateLLVMFunction(Name, Ty, GlobalDecl(FD), /*ForVTable=*/false);
+  return GetOrCreateLLVMFunction(Name, Ty, D, /*ForVTable=*/false);
 }
 
 llvm::Function *CodeGenModule::getIntrinsic(unsigned IID,const llvm::Type **Tys,
