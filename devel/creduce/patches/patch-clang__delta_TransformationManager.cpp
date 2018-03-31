$NetBSD: patch-clang__delta_TransformationManager.cpp,v 1.2 2018/03/31 20:09:10 joerg Exp $

--- clang_delta/TransformationManager.cpp.orig	2018-03-31 19:32:59.198705133 +0000
+++ clang_delta/TransformationManager.cpp
@@ -99,18 +99,18 @@ bool TransformationManager::initializeCo
   }
   llvm::Triple T(TargetOpts.Triple);
   CompilerInvocation &Invocation = ClangInstance->getInvocation();
-  InputKind IK = FrontendOptions::getInputKindForExtension(
-        StringRef(SrcFileName).rsplit('.').second);
-  if ((IK == IK_C) || (IK == IK_PreprocessedC)) {
-    Invocation.setLangDefaults(ClangInstance->getLangOpts(), IK_C, T, PPOpts);
+  InputKind::Language IK = FrontendOptions::getInputKindForExtension(
+        StringRef(SrcFileName).rsplit('.').second).getLanguage();
+  if (IK == InputKind::C) {
+    Invocation.setLangDefaults(ClangInstance->getLangOpts(), InputKind::C, T, PPOpts);
   }
-  else if ((IK == IK_CXX) || (IK == IK_PreprocessedCXX)) {
+  else if (IK == InputKind::CXX) {
     // ISSUE: it might cause some problems when building AST
     // for a function which has a non-declared callee, e.g., 
     // It results an empty AST for the caller. 
-    Invocation.setLangDefaults(ClangInstance->getLangOpts(), IK_CXX, T, PPOpts);
+    Invocation.setLangDefaults(ClangInstance->getLangOpts(), InputKind::CXX, T, PPOpts);
   }
-  else if(IK == IK_OpenCL) {
+  else if(IK == InputKind::OpenCL) {
     //Commandline parameters
     std::vector<const char*> Args;
     Args.push_back("-x");
@@ -135,7 +135,7 @@ bool TransformationManager::initializeCo
                                        &Args[0], &Args[0] + Args.size(),
                                        ClangInstance->getDiagnostics());
     Invocation.setLangDefaults(ClangInstance->getLangOpts(),
-                               IK_OpenCL, T, PPOpts);
+                               InputKind::OpenCL, T, PPOpts);
   }
   else {
     ErrorMsg = "Unsupported file type!";
