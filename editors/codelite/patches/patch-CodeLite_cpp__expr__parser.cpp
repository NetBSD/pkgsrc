$NetBSD: patch-CodeLite_cpp__expr__parser.cpp,v 1.2 2023/11/02 12:04:02 nros Exp $

Fix Warning: ISO C++ forbids converting a string constant to char*

--- CodeLite/cpp_expr_parser.cpp.orig	2023-10-26 10:47:53.397149452 +0000
+++ CodeLite/cpp_expr_parser.cpp
@@ -530,6 +530,8 @@ int
 yyparse()
 {
     register int yym, yyn, yystate;
+    char semsg[] = "syntax error";
+    char ysomsg[] = "yacc stack overflow";
 #if YYDEBUG
     register char *yys;
     extern char *getenv();
@@ -595,7 +597,7 @@ yyloop:
     goto yynewerror;
 #endif
 yynewerror:
-    yyerror("syntax error");
+    yyerror(semsg);
 #ifdef lint
     goto yyerrlab;
 #endif
@@ -968,7 +970,7 @@ to state %d\n", YYPREFIX, *yyssp, yystat
     *++yyvsp = yyval;
     goto yyloop;
 yyoverflow:
-    yyerror("yacc stack overflow");
+    yyerror(ysomsg);
 yyabort:
     return (1);
 yyaccept:
