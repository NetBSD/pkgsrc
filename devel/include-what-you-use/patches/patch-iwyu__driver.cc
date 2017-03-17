$NetBSD: patch-iwyu__driver.cc,v 1.1 2017/03/17 22:39:31 adam Exp $

Fix for LLVM 4.0.0.

--- iwyu_driver.cc.orig	2017-03-17 20:52:13.000000000 +0000
+++ iwyu_driver.cc
@@ -207,7 +207,7 @@ CompilerInstance* CreateCompilerInstance
   const ArgStringList &cc_arguments = command.getArguments();
   const char** args_start = const_cast<const char**>(cc_arguments.data());
   const char** args_end = args_start + cc_arguments.size();
-  unique_ptr<CompilerInvocation> invocation(new CompilerInvocation);
+  std::shared_ptr<CompilerInvocation> invocation(new CompilerInvocation);
   CompilerInvocation::CreateFromArgs(*invocation,
                                      args_start, args_end, diagnostics);
   invocation->getFrontendOpts().DisableFree = false;
@@ -238,7 +238,7 @@ CompilerInstance* CreateCompilerInstance
   // Create a compiler instance to handle the actual work.
   // The caller will be responsible for freeing this.
   CompilerInstance* compiler = new CompilerInstance;
-  compiler->setInvocation(invocation.release());
+  compiler->setInvocation(invocation);
 
   // Create the compilers actual diagnostics engine.
   compiler->createDiagnostics();
