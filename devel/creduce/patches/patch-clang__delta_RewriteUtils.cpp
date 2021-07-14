$NetBSD: patch-clang__delta_RewriteUtils.cpp,v 1.3 2021/07/14 09:08:49 wiz Exp $

Build fix for llvm 12.0.1 from https://github.com/csmith-project/creduce/tree/llvm-12.0-dev

--- clang_delta/RewriteUtils.cpp.orig	2019-05-13 21:17:30.000000000 +0000
+++ clang_delta/RewriteUtils.cpp
@@ -718,8 +718,8 @@ std::string RewriteUtils::getStmtIndentS
   StringRef MB = SrcManager->getBufferData(FID);
  
   unsigned lineNo = SrcManager->getLineNumber(FID, StartOffset) - 1;
-  const SrcMgr::ContentCache *
-      Content = SrcManager->getSLocEntry(FID).getFile().getContentCache();
+  const SrcMgr::ContentCache *Content =
+    &SrcManager->getSLocEntry(FID).getFile().getContentCache();
   unsigned lineOffs = Content->SourceLineCache[lineNo];
  
   // Find the whitespace at the start of the line.
@@ -730,7 +730,7 @@ std::string RewriteUtils::getStmtIndentS
     ++I;
   indentSpace = MB.substr(lineOffs, I-lineOffs);
 
-  return indentSpace;
+  return indentSpace.str();
 }
 
 bool RewriteUtils::addLocalVarToFunc(const std::string &VarStr,
