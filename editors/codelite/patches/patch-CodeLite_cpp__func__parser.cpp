$NetBSD: patch-CodeLite_cpp__func__parser.cpp,v 1.1 2023/10/26 10:46:58 nros Exp $

Fix Warning: ISO C++ forbids converting a string constant to char*

--- CodeLite/cpp_func_parser.cpp.orig	2023-10-25 12:56:08.665232425 +0000
+++ CodeLite/cpp_func_parser.cpp
@@ -55,6 +55,8 @@ void cl_func_error(char *string);
 static FunctionList *g_funcs = NULL;
 static clFunction curr_func;
 
+static char semsg[] = "syntax error";
+static char ysomsg[] = "yacc stack overflow";
 /*---------------------------------------------*/
 /* externs defined in the lexer*/
 /*---------------------------------------------*/
@@ -689,7 +691,7 @@ yyloop:
     goto yynewerror;
 #endif
 yynewerror:
-    yyerror("syntax error");
+    yyerror(semsg);
 #ifdef lint
     goto yyerrlab;
 #endif
@@ -1042,7 +1044,7 @@ to state %d\n", YYPREFIX, *yyssp, yystat
     *++yyvsp = yyval;
     goto yyloop;
 yyoverflow:
-    yyerror("yacc stack overflow");
+    yyerror(ysomsg);
 yyabort:
     return (1);
 yyaccept:
