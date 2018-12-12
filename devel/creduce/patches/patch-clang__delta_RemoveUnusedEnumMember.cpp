$NetBSD: patch-clang__delta_RemoveUnusedEnumMember.cpp,v 1.1 2018/12/12 12:44:43 adam Exp $

Fix for LLVM 7.0.
https://github.com/csmith-project/creduce/tree/llvm-7.0

--- clang_delta/RemoveUnusedEnumMember.cpp.orig	2018-12-12 12:36:01.000000000 +0000
+++ clang_delta/RemoveUnusedEnumMember.cpp
@@ -99,15 +99,15 @@ void RemoveUnusedEnumMember::removeEnumC
 {
   SourceLocation StartLoc = (*TheEnumIterator)->getLocStart();
   if (StartLoc.isMacroID()) {
-    std::pair<SourceLocation, SourceLocation> Locs =
+    CharSourceRange CSRange =
       SrcManager->getExpansionRange(StartLoc);
-    StartLoc = Locs.first;
+    StartLoc = CSRange.getBegin();
   }
   SourceLocation EndLoc = (*TheEnumIterator)->getLocEnd();
   if (EndLoc.isMacroID()) {
-    std::pair<SourceLocation, SourceLocation> Locs =
+    CharSourceRange CSRange =
       SrcManager->getExpansionRange(EndLoc);
-    EndLoc = Locs.second;
+    EndLoc = CSRange.getEnd();
   }
   SourceLocation CommaLoc = Lexer::findLocationAfterToken(
     EndLoc, tok::comma, *SrcManager, Context->getLangOpts(),
