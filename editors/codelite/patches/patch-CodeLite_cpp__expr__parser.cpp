$NetBSD: patch-CodeLite_cpp__expr__parser.cpp,v 1.1 2023/10/26 10:46:58 nros Exp $

Fix Warning: ISO C++ forbids converting a string constant to char*

--- CodeLite/cpp_expr_parser.cpp.orig	2023-10-25 12:56:08.662150675 +0000
+++ CodeLite/cpp_expr_parser.cpp
@@ -47,6 +47,9 @@ void cl_expr_error(char *string);
 
 static ExpressionResult result;
 
+static char semsg[] = "syntax error";
+static char ysomsg[] = "yacc stack overflow";
+
 /*---------------------------------------------*/
 /* externs defined in the lexer*/
 /*---------------------------------------------*/
@@ -595,7 +598,7 @@ yyloop:
     goto yynewerror;
 #endif
 yynewerror:
-    yyerror("syntax error");
+    yyerror(semsg);
 #ifdef lint
     goto yyerrlab;
 #endif
@@ -968,7 +971,7 @@ to state %d\n", YYPREFIX, *yyssp, yystat
     *++yyvsp = yyval;
     goto yyloop;
 yyoverflow:
-    yyerror("yacc stack overflow");
+    yyerror(ysomsg);
 yyabort:
     return (1);
 yyaccept:
