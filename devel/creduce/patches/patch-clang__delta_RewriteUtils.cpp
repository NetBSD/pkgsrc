$NetBSD: patch-clang__delta_RewriteUtils.cpp,v 1.1 2016/11/18 18:20:05 joerg Exp $

--- clang_delta/RewriteUtils.cpp.orig	2016-11-17 01:55:03.000000000 +0000
+++ clang_delta/RewriteUtils.cpp
@@ -1701,7 +1701,7 @@ bool RewriteUtils::removeClassDecls(cons
     SourceRange Range = (*I)->getSourceRange();
     SourceLocation LocEnd;
     if ((*I)->isThisDeclarationADefinition()) {
-      LocEnd = (*I)->getRBraceLoc();
+      LocEnd = (*I)->getBraceRange().getEnd();
       if (LocEnd.isValid())
         LocEnd = getLocationUntil(LocEnd, ';');
       else
@@ -1726,7 +1726,7 @@ bool RewriteUtils::removeClassTemplateDe
     SourceRange Range = (*I)->getSourceRange();
     SourceLocation LocEnd;
     if (CXXRD->isThisDeclarationADefinition()) {
-      LocEnd = CXXRD->getRBraceLoc();
+      LocEnd = CXXRD->getBraceRange().getEnd();
       LocEnd = getLocationUntil(LocEnd, ';');
     }
     else {
