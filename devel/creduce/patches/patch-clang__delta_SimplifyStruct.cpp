$NetBSD: patch-clang__delta_SimplifyStruct.cpp,v 1.1 2016/11/18 18:20:05 joerg Exp $

--- clang_delta/SimplifyStruct.cpp.orig	2016-11-17 01:56:34.000000000 +0000
+++ clang_delta/SimplifyStruct.cpp
@@ -173,7 +173,7 @@ bool SimplifyStructRewriteVisitor::Visit
 
   SourceLocation LBLoc =
     ConsumerInstance->RewriteHelper->getLocationUntil(RD->getLocation(), '{');
-  SourceLocation RBLoc = RD->getRBraceLoc();
+  SourceLocation RBLoc = RD->getBraceRange().getEnd();
   ConsumerInstance->TheRewriter.RemoveText(SourceRange(LBLoc, RBLoc));
   return true;
 }
