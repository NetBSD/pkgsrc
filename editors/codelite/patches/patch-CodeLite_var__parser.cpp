$NetBSD: patch-CodeLite_var__parser.cpp,v 1.1 2023/10/26 10:46:58 nros Exp $

Fix Warning: ISO C++ forbids converting a string constant to char*

--- CodeLite/var_parser.cpp.orig	2023-10-25 12:56:08.670851597 +0000
+++ CodeLite/var_parser.cpp
@@ -62,6 +62,8 @@ static  std::string           s_tmpStrin
 static  Variable              curr_var;
 static  std::string           s_templateInitList;
 static  bool                  isBasicType = false;
+static  char semsg[] = "syntax error";
+static  char ysomsg[] = "yacc stack overflow";
 
 /*---------------------------------------------*/
 /* externs defined in the lexer*/
@@ -810,7 +812,7 @@ yyloop:
     goto yynewerror;
 #endif
 yynewerror:
-    yyerror("syntax error");
+    yyerror(semsg);
 #ifdef lint
     goto yyerrlab;
 #endif
@@ -1414,7 +1416,7 @@ to state %d\n", YYPREFIX, *yyssp, yystat
     *++yyvsp = yyval;
     goto yyloop;
 yyoverflow:
-    yyerror("yacc stack overflow");
+    yyerror(ysomsg);
 yyabort:
     return (1);
 yyaccept:
