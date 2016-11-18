$NetBSD: patch-clang__delta_EmptyStructToInt.cpp,v 1.1 2016/11/18 18:20:05 joerg Exp $

--- clang_delta/EmptyStructToInt.cpp.orig	2016-11-17 01:42:53.000000000 +0000
+++ clang_delta/EmptyStructToInt.cpp
@@ -351,7 +351,7 @@ void EmptyStructToInt::removeRecordDecls
     if (SemiLoc.isInvalid()) {
       if (!RD->isThisDeclarationADefinition())
         return;
-      SourceLocation RBLoc = RD->getRBraceLoc();
+      SourceLocation RBLoc = RD->getBraceRange().getEnd();
       if (RBLoc.isInvalid())
         return;
       RewriteHelper->removeTextFromLeftAt(SourceRange(RBLoc, RBLoc),
