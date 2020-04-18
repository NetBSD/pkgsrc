$NetBSD: patch-ffi_linker.cpp,v 1.1 2020/04/18 08:11:53 adam Exp $

Fix building with newer LLVM.

--- ffi/linker.cpp.orig	2020-04-17 20:19:54.000000000 +0000
+++ ffi/linker.cpp
@@ -42,7 +42,7 @@ LLVMPY_LinkModules(LLVMModuleRef Dest, L
     auto OldDiagnosticHandler = Ctx.getDiagnosticHandler();
 
     // set the handler to a new one
-    Ctx.setDiagnosticHandler(llvm::make_unique<ReportNotAbortDiagnosticHandler>(errstream));
+    Ctx.setDiagnosticHandler(std::make_unique<ReportNotAbortDiagnosticHandler>(errstream));
 
     // link
     bool failed = LLVMLinkModules2(Dest, Src);
