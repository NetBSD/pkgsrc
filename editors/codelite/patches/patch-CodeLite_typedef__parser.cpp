$NetBSD: patch-CodeLite_typedef__parser.cpp,v 1.1 2023/10/26 10:46:58 nros Exp $

Fix Warning: ISO C++ forbids converting a string constant to char*

--- CodeLite/typedef_parser.cpp.orig	2023-10-25 12:56:08.668865476 +0000
+++ CodeLite/typedef_parser.cpp
@@ -62,6 +62,8 @@ static  Variable                 curr_va
 static  clTypedefList            gs_typedefs;
 static  clTypedef                gs_currentTypedef;
 static  std::string              s_templateInitList;
+static  char semsg[] = "syntax error";
+static  char ysomsg[] = "yacc stack overflow";
 
 /*---------------------------------------------*/
 /* externs defined in the lexer*/
@@ -605,7 +607,7 @@ yyloop:
     goto yynewerror;
 #endif
 yynewerror:
-    yyerror("syntax error");
+    yyerror(semsg);
 #ifdef lint
     goto yyerrlab;
 #endif
@@ -955,7 +957,7 @@ to state %d\n", YYPREFIX, *yyssp, yystat
     *++yyvsp = yyval;
     goto yyloop;
 yyoverflow:
-    yyerror("yacc stack overflow");
+    yyerror(ysomsg);
 yyabort:
     return (1);
 yyaccept:
