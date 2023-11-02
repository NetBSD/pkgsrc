$NetBSD: patch-CodeLite_var__parser.cpp,v 1.2 2023/11/02 12:04:02 nros Exp $

Fix Warning: ISO C++ forbids converting a string constant to char*

--- CodeLite/var_parser.cpp.orig	2023-10-26 10:47:53.407870798 +0000
+++ CodeLite/var_parser.cpp
@@ -745,6 +745,8 @@ int
 yyparse()
 {
     register int yym, yyn, yystate;
+    char semsg[] = "syntax error";
+    char ysomsg[] = "yacc stack overflow";
 #if YYDEBUG
     register char *yys;
     extern char *getenv();
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
