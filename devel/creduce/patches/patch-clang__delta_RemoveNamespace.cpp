$NetBSD: patch-clang__delta_RemoveNamespace.cpp,v 1.1 2021/07/14 09:08:49 wiz Exp $

Build fix for llvm 12.0.1 from https://github.com/csmith-project/creduce/tree/llvm-12.0-dev

--- clang_delta/RemoveNamespace.cpp.orig	2019-05-13 21:17:30.000000000 +0000
+++ clang_delta/RemoveNamespace.cpp
@@ -458,7 +458,7 @@ bool RemoveNamespaceRewriteVisitor::Visi
   TransAssert(DTST && "Bad DependentTemplateSpecializationType!");
 
   const IdentifierInfo *IdInfo = DTST->getIdentifier();
-  std::string IdName = IdInfo->getName();
+  std::string IdName = IdInfo->getName().str();
   std::string Name;
 
   // FIXME:
