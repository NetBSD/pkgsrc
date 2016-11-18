$NetBSD: patch-clang__delta_RemoveUnusedOuterClass.cpp,v 1.1 2016/11/18 18:20:05 joerg Exp $

--- clang_delta/RemoveUnusedOuterClass.cpp.orig	2016-11-17 01:53:49.000000000 +0000
+++ clang_delta/RemoveUnusedOuterClass.cpp
@@ -140,7 +140,7 @@ void RemoveUnusedOuterClass::removeOuter
     TheRewriter.RemoveText(AS->getSourceRange());
   }
   
-  LocStart = TheCXXRDDef->getRBraceLoc();
+  LocStart = TheCXXRDDef->getBraceRange().getEnd();
   LocEnd = RewriteHelper->getLocationUntil(LocStart, ';');
   if (LocStart.isInvalid() || LocEnd.isInvalid())
     return;
