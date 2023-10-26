$NetBSD: patch-CodeLite_scope__parser.cpp,v 1.1 2023/10/26 10:46:58 nros Exp $

Fix Warning: ISO C++ forbids converting a string constant to char*

--- CodeLite/scope_parser.cpp.orig	2023-10-25 12:56:08.667128461 +0000
+++ CodeLite/scope_parser.cpp
@@ -54,6 +54,8 @@ void cl_scope_error(char *string);
 void syncParser();
 
 static std::vector<std::string> gs_additionlNS;
+static char semsg[] = "syntax error";
+static char ysomsg[] = "yacc stack overflow";
 
 /*---------------------------------------------*/
 /* externs defined in the lexer*/
@@ -899,7 +901,7 @@ yyloop:
     goto yynewerror;
 #endif
 yynewerror:
-    yyerror("syntax error");
+    yyerror(semsg);
 #ifdef lint
     goto yyerrlab;
 #endif
@@ -1354,7 +1356,7 @@ to state %d\n", YYPREFIX, *yyssp, yystat
     *++yyvsp = yyval;
     goto yyloop;
 yyoverflow:
-    yyerror("yacc stack overflow");
+    yyerror(ysomsg);
 yyabort:
     return (1);
 yyaccept:
