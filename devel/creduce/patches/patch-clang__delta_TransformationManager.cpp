$NetBSD: patch-clang__delta_TransformationManager.cpp,v 1.6 2020/04/20 16:33:51 adam Exp $

Port to LLVM 10.0
https://github.com/csmith-project/creduce/pull/204/

--- clang_delta/TransformationManager.cpp.orig	2019-05-13 21:17:30.000000000 +0000
+++ clang_delta/TransformationManager.cpp
@@ -16,6 +16,7 @@
 
 #include <sstream>
 
+#include "clang/Basic/Builtins.h"
 #include "clang/Basic/Diagnostic.h"
 #include "clang/Basic/TargetInfo.h"
 #include "clang/Lex/Preprocessor.h"
@@ -101,6 +102,7 @@ bool TransformationManager::initializeCo
   CompilerInvocation &Invocation = ClangInstance->getInvocation();
   InputKind IK = FrontendOptions::getInputKindForExtension(
         StringRef(SrcFileName).rsplit('.').second);
+#if LLVM_VERSION_MAJOR < 10
   if (IK.getLanguage() == InputKind::C) {
     Invocation.setLangDefaults(ClangInstance->getLangOpts(), InputKind::C, T, PPOpts);
   }
@@ -111,6 +113,18 @@ bool TransformationManager::initializeCo
     Invocation.setLangDefaults(ClangInstance->getLangOpts(), InputKind::CXX, T, PPOpts);
   }
   else if(IK.getLanguage() == InputKind::OpenCL) {
+#else
+  if (IK.getLanguage() == Language::C) {
+    Invocation.setLangDefaults(ClangInstance->getLangOpts(), InputKind(Language::C), T, PPOpts);
+  }
+  else if (IK.getLanguage() == Language::CXX) {
+    // ISSUE: it might cause some problems when building AST
+    // for a function which has a non-declared callee, e.g.,
+    // It results an empty AST for the caller.
+    Invocation.setLangDefaults(ClangInstance->getLangOpts(), InputKind(Language::CXX), T, PPOpts);
+  }
+  else if(IK.getLanguage() == Language::OpenCL) {
+#endif
     //Commandline parameters
     std::vector<const char*> Args;
     Args.push_back("-x");
@@ -122,7 +136,7 @@ bool TransformationManager::initializeCo
     ClangInstance->createFileManager();
 
     if(CLCPath != NULL && ClangInstance->hasFileManager() &&
-       ClangInstance->getFileManager().getDirectory(CLCPath, false) != NULL) {
+       ClangInstance->getFileManager().getDirectory(CLCPath, false)) {
         Args.push_back("-I");
         Args.push_back(CLCPath);
     }
@@ -132,10 +146,19 @@ bool TransformationManager::initializeCo
     Args.push_back("-fno-builtin");
 
     CompilerInvocation::CreateFromArgs(Invocation,
+#if LLVM_VERSION_MAJOR >= 10
+                                       Args,
+#else
                                        &Args[0], &Args[0] + Args.size(),
+#endif
                                        ClangInstance->getDiagnostics());
     Invocation.setLangDefaults(ClangInstance->getLangOpts(),
-                               InputKind::OpenCL, T, PPOpts);
+#if LLVM_VERSION_MAJOR >= 10
+                               InputKind(Language::OpenCL),
+#else
+                               InputKind::OpenCL,
+#endif
+			       T, PPOpts);
   }
   else {
     ErrorMsg = "Unsupported file type!";
