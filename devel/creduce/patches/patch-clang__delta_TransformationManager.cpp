$NetBSD: patch-clang__delta_TransformationManager.cpp,v 1.1 2016/11/18 18:20:05 joerg Exp $

--- clang_delta/TransformationManager.cpp.orig	2016-11-17 01:58:56.000000000 +0000
+++ clang_delta/TransformationManager.cpp
@@ -82,6 +82,16 @@ bool TransformationManager::initializeCo
 
   ClangInstance = new CompilerInstance();
   assert(ClangInstance);
+
+  TargetOptions &TargetOpts = ClangInstance->getTargetOpts();
+  PreprocessorOptions &PPOpts = ClangInstance->getPreprocessorOpts();
+
+  if (const char *env = getenv("CREDUCE_TARGET_TRIPLE")) {
+    TargetOpts.Triple = std::string(env);
+  } else {
+    TargetOpts.Triple = LLVM_DEFAULT_TARGET_TRIPLE;
+  }
+  llvm::Triple Triple(TargetOpts.Triple);
   
   ClangInstance->createDiagnostics();
 
@@ -89,13 +99,13 @@ bool TransformationManager::initializeCo
   InputKind IK = FrontendOptions::getInputKindForExtension(
         StringRef(SrcFileName).rsplit('.').second);
   if ((IK == IK_C) || (IK == IK_PreprocessedC)) {
-    Invocation.setLangDefaults(ClangInstance->getLangOpts(), IK_C);
+    Invocation.setLangDefaults(ClangInstance->getLangOpts(), IK_C, Triple, PPOpts);
   }
   else if ((IK == IK_CXX) || (IK == IK_PreprocessedCXX)) {
     // ISSUE: it might cause some problems when building AST
     // for a function which has a non-declared callee, e.g., 
     // It results an empty AST for the caller. 
-    Invocation.setLangDefaults(ClangInstance->getLangOpts(), IK_CXX);
+    Invocation.setLangDefaults(ClangInstance->getLangOpts(), IK_CXX, Triple, PPOpts);
   }
   else if(IK == IK_OpenCL) {
     //Commandline parameters
@@ -121,21 +131,13 @@ bool TransformationManager::initializeCo
     CompilerInvocation::CreateFromArgs(Invocation,
                                        &Args[0], &Args[0] + Args.size(),
                                        ClangInstance->getDiagnostics());
-    Invocation.setLangDefaults(ClangInstance->getLangOpts(), IK_OpenCL);
+    Invocation.setLangDefaults(ClangInstance->getLangOpts(), IK_OpenCL, Triple, PPOpts);
   }
   else {
     ErrorMsg = "Unsupported file type!";
     return false;
   }
 
-  TargetOptions &TargetOpts = ClangInstance->getTargetOpts();
-
-  if (const char *env = getenv("CREDUCE_TARGET_TRIPLE")) {
-    TargetOpts.Triple = std::string(env);
-  } else {
-    TargetOpts.Triple = LLVM_DEFAULT_TARGET_TRIPLE;
-  }
-
   TargetInfo *Target = 
     TargetInfo::CreateTargetInfo(ClangInstance->getDiagnostics(),
                                  ClangInstance->getInvocation().TargetOpts);
