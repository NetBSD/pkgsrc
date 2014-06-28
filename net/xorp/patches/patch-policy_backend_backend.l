$NetBSD: patch-policy_backend_backend.l,v 1.2 2014/06/28 20:19:41 dholland Exp $

- turn on no input because ... (XXX why?)
- add cast to work with more lex versions

--- policy/backend/backend.l.orig	2008-08-06 08:24:59.000000000 +0000
+++ policy/backend/backend.l
@@ -33,6 +33,7 @@ namespace {
 %}
 %option noyywrap
 %option nounput
+%option noinput
 %option prefix="yy_policy_backend_parser"
 %option outfile="lex.yy_policy_backend_parser.cc"
 %option never-interactive
@@ -100,7 +101,7 @@ void yyerror(const char *m)
         ostringstream oss;
 
         oss << "Error on line " <<  _parser_lineno << " near (";
-        for(int i = 0; i < yyleng; i++)
+        for(int i = 0; i < (int)yyleng; i++)
                 oss << yytext[i];
         oss << "): " << m;
 
