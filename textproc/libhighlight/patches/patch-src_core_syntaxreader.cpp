$NetBSD: patch-src_core_syntaxreader.cpp,v 1.1 2024/08/16 15:27:59 schmonz Exp $

Apply upstream commit edf6511e to fix #247.

--- src/core/syntaxreader.cpp.orig	2024-08-11 13:05:37.000000000 +0000
+++ src/core/syntaxreader.cpp
@@ -65,8 +65,21 @@ set<string> SyntaxReader::persistentSynt
 int RegexElement::instanceCnt=0;
 
 
-SyntaxReader::SyntaxReader() 
-    
+SyntaxReader::SyntaxReader() :
+  ignoreCase ( false ),
+  disableHighlighting ( false ),
+  allowNestedComments ( true ),
+  reformatCode ( false ),
+  assertEqualLength(false),
+  paramsNeedUpdate(false),
+  rawStringPrefix(0),
+  continuationChar(0),
+  keywordCount(0),
+  validateStateChangeFct(nullptr),
+  decorateFct(nullptr),
+  decorateLineBeginFct(nullptr),
+  decorateLineEndFct(nullptr),
+  luaState(nullptr)
 {
 
 }
