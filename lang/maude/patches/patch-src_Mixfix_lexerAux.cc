$NetBSD: patch-src_Mixfix_lexerAux.cc,v 1.2 2015/12/29 23:34:51 dholland Exp $

Fix build with newer bison.

--- src/Mixfix/lexerAux.cc.orig	2013-11-28 00:54:41.000000000 +0000
+++ src/Mixfix/lexerAux.cc
@@ -35,7 +35,7 @@ bool fakeNewline = false;  // fake \n fo
 bool fakeNewlineStack[MAX_IN_DEPTH];
 
 void
-getInput(char* buf, int& result, int max_size)
+getInput(char* buf, size_t& result, int max_size)
 {
   result = YY_NULL;
   if (UserLevelRewritingContext::interrupted())
