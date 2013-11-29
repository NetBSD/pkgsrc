$NetBSD: patch-src_Mixfix_bottom.yy,v 1.1 2013/11/29 18:30:10 joerg Exp $

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
