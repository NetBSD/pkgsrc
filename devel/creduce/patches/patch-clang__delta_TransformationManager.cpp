$NetBSD: patch-clang__delta_TransformationManager.cpp,v 1.7 2021/07/14 09:08:49 wiz Exp $

Build fix for llvm 12.0.1 from https://github.com/csmith-project/creduce/tree/llvm-12.0-dev

--- clang_delta/TransformationManager.cpp.orig	2019-05-13 21:17:30.000000000 +0000
+++ clang_delta/TransformationManager.cpp
@@ -16,9 +16,12 @@
 
 #include <sstream>
 
+#include "clang/Basic/Builtins.h"
 #include "clang/Basic/Diagnostic.h"
+#include "clang/Basic/FileManager.h"
 #include "clang/Basic/TargetInfo.h"
 #include "clang/Lex/Preprocessor.h"
+#include "clang/Lex/PreprocessorOptions.h"
 #include "clang/Frontend/CompilerInstance.h"
 #include "clang/Parse/ParseAST.h"
 
@@ -101,16 +104,16 @@ bool TransformationManager::initializeCo
   CompilerInvocation &Invocation = ClangInstance->getInvocation();
   InputKind IK = FrontendOptions::getInputKindForExtension(
         StringRef(SrcFileName).rsplit('.').second);
-  if (IK.getLanguage() == InputKind::C) {
-    Invocation.setLangDefaults(ClangInstance->getLangOpts(), InputKind::C, T, PPOpts);
+  if (IK.getLanguage() == Language::C) {
+    Invocation.setLangDefaults(ClangInstance->getLangOpts(), Language::C, T, PPOpts.Includes);
   }
-  else if (IK.getLanguage() == InputKind::CXX) {
+  else if (IK.getLanguage() == Language::CXX) {
     // ISSUE: it might cause some problems when building AST
     // for a function which has a non-declared callee, e.g.,
     // It results an empty AST for the caller.
-    Invocation.setLangDefaults(ClangInstance->getLangOpts(), InputKind::CXX, T, PPOpts);
+    Invocation.setLangDefaults(ClangInstance->getLangOpts(), Language::CXX, T, PPOpts.Includes);
   }
-  else if(IK.getLanguage() == InputKind::OpenCL) {
+  else if(IK.getLanguage() == Language::OpenCL) {
     //Commandline parameters
     std::vector<const char*> Args;
     Args.push_back("-x");
@@ -122,7 +125,7 @@ bool TransformationManager::initializeCo
     ClangInstance->createFileManager();
 
     if(CLCPath != NULL && ClangInstance->hasFileManager() &&
-       ClangInstance->getFileManager().getDirectory(CLCPath, false) != NULL) {
+       ClangInstance->getFileManager().getDirectory(CLCPath, false)) {
         Args.push_back("-I");
         Args.push_back(CLCPath);
     }
@@ -132,10 +135,10 @@ bool TransformationManager::initializeCo
     Args.push_back("-fno-builtin");
 
     CompilerInvocation::CreateFromArgs(Invocation,
-                                       &Args[0], &Args[0] + Args.size(),
+		                       ArrayRef<const char*>(&Args[0], &Args[0] + Args.size()),
                                        ClangInstance->getDiagnostics());
     Invocation.setLangDefaults(ClangInstance->getLangOpts(),
-                               InputKind::OpenCL, T, PPOpts);
+                               Language::OpenCL, T, PPOpts.Includes);
   }
   else {
     ErrorMsg = "Unsupported file type!";
