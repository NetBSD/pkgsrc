$NetBSD: patch-clang__delta_RemoveBaseClass.cpp,v 1.1 2016/11/18 18:20:05 joerg Exp $

--- clang_delta/RemoveBaseClass.cpp.orig	2016-11-17 01:45:06.000000000 +0000
+++ clang_delta/RemoveBaseClass.cpp
@@ -209,7 +209,7 @@ void RemoveBaseClass::copyBaseClassDecls
     return;
   SourceLocation StartLoc = 
     RewriteHelper->getLocationAfter(TheBaseClass->getLocation(), '{');
-  SourceLocation EndLoc = TheBaseClass->getRBraceLoc();
+  SourceLocation EndLoc = TheBaseClass->getBraceRange().getEnd();
   TransAssert(EndLoc.isValid() && "Invalid RBraceLoc!");
   EndLoc = EndLoc.getLocWithOffset(-1);
 
@@ -217,7 +217,7 @@ void RemoveBaseClass::copyBaseClassDecls
     TheRewriter.getRewrittenText(SourceRange(StartLoc, EndLoc));
 
   TransAssert(!DeclsStr.empty() && "Empty DeclsStr!");
-  SourceLocation InsertLoc = TheDerivedClass->getRBraceLoc();
+  SourceLocation InsertLoc = TheDerivedClass->getBraceRange().getEnd();
   TheRewriter.InsertTextBefore(InsertLoc, DeclsStr);
 }
 
