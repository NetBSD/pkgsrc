$NetBSD: patch-policy_policy.l,v 1.2 2014/06/28 23:40:12 dholland Exp $

- turn on no input because ... (XXX why?)
- add cast to work with more lex versions

--- policy/policy.l.orig	2008-08-06 08:25:49.000000000 +0000
+++ policy/policy.l
@@ -35,6 +35,7 @@ namespace {
 %option outfile="lex.yy_policy_parser.cc"
 %option noyywrap
 %option nounput
+%option noinput
 %option never-interactive
 %x STR
 
@@ -193,7 +194,7 @@ void yyerror(const char *m)
         ostringstream oss;
         oss << "Error on line " <<  _parser_lineno << " near (";
 
-	for(int i = 0; i < yyleng; i++)
+	for(int i = 0; i < (int)yyleng; i++)
 		oss << yytext[i];
 	oss << "): " << m;
 
