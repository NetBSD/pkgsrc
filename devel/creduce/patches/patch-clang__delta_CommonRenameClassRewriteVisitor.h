$NetBSD: patch-clang__delta_CommonRenameClassRewriteVisitor.h,v 1.1 2021/07/14 09:08:49 wiz Exp $

Build fix for llvm 12.0.1 from https://github.com/csmith-project/creduce/tree/llvm-12.0-dev

--- clang_delta/CommonRenameClassRewriteVisitor.h.orig	2019-05-13 21:17:30.000000000 +0000
+++ clang_delta/CommonRenameClassRewriteVisitor.h
@@ -98,7 +98,7 @@ bool CommonRenameClassRewriteVisitor<T>:
     return true;
 
   IdentifierInfo *IdInfo = DeclName.getAsIdentifierInfo();
-  std::string IdName = IdInfo->getName();
+  std::string IdName = IdInfo->getName().str();
   std::string Name;
   if (getNewNameByName(IdName, Name)) {
     SourceLocation LocStart = NameInfo.getBeginLoc();
@@ -332,7 +332,7 @@ template<typename T> bool CommonRenameCl
   TransAssert(DTST && "Bad DependentTemplateSpecializationType!");
 
   const IdentifierInfo *IdInfo = DTST->getIdentifier();
-  std::string IdName = IdInfo->getName();
+  std::string IdName = IdInfo->getName().str();
   std::string Name;
   if (getNewNameByName(IdName, Name)) {
     SourceLocation LocStart = DTSLoc.getTemplateNameLoc();
