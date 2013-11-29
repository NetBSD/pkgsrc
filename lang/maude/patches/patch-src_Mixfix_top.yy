$NetBSD: patch-src_Mixfix_top.yy,v 1.1 2013/11/29 18:30:10 joerg Exp $

--- src/Mixfix/top.yy.orig	2013-11-28 01:19:24.000000000 +0000
+++ src/Mixfix/top.yy
@@ -59,7 +59,6 @@
 #define store(token)		tokenSequence.append(token)
 #define fragClear()		fragments.contractTo(0);
 #define fragStore(token)	fragments.append(token)
-#define YYPARSE_PARAM	parseResult
 #define PARSE_RESULT	(*((UserLevelRewritingContext::ParseResult*) parseResult))
 
 #define CM		interpreter.getCurrentModule()
@@ -91,13 +90,14 @@ SyntaxContainer* oldSyntaxContainer = 0;
 Int64 number;
 Int64 number2;
 
-static void yyerror(char *s);
+static void yyerror(UserLevelRewritingContext::ParseResult *parseResult, char *s);
 
 void cleanUpModuleExpression();
 void cleanUpParser();
 void missingSpace(const Token& token);
 %}
-%pure_parser
+%parse-param { UserLevelRewritingContext::ParseResult *parseResult }
+%pure-parser
 
 %union
 {
