$NetBSD: patch-src_Mixfix_bottom.yy,v 1.2 2015/12/29 23:34:51 dholland Exp $

Fix build with newer bison.

--- src/Mixfix/bottom.yy.orig	2013-11-28 01:19:40.000000000 +0000
+++ src/Mixfix/bottom.yy
@@ -23,7 +23,7 @@
 %%
 
 static void
-yyerror(char *s)
+yyerror(UserLevelRewritingContext::ParseResult *parseResult, char *s)
 {
   if (!(UserLevelRewritingContext::interrupted()))
     IssueWarning(LineNumber(lineNumber) << ": " << s);
