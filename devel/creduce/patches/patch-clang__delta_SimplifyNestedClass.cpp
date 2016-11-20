$NetBSD: patch-clang__delta_SimplifyNestedClass.cpp,v 1.1 2016/11/20 22:14:07 joerg Exp $

--- clang_delta/SimplifyNestedClass.cpp.orig	2016-11-19 11:31:59.000000000 +0000
+++ clang_delta/SimplifyNestedClass.cpp
@@ -140,7 +140,7 @@ void SimplifyNestedClass::removeOuterCla
   LocEnd = LocEnd.getLocWithOffset(-1);
   TheRewriter.RemoveText(SourceRange(LocStart, LocEnd));
 
-  LocStart = TheBaseCXXRD->getRBraceLoc();
+  LocStart = TheBaseCXXRD->getBraceRange().getEnd();
   LocEnd = RewriteHelper->getLocationUntil(LocStart, ';');
   if (LocStart.isInvalid() || LocEnd.isInvalid())
     return;
