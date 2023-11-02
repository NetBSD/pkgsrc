$NetBSD: patch-CodeLite_scope__parser.cpp,v 1.2 2023/11/02 12:04:02 nros Exp $

Fix Warning: ISO C++ forbids converting a string constant to char*

--- CodeLite/scope_parser.cpp.orig	2023-10-26 10:47:53.402699303 +0000
+++ CodeLite/scope_parser.cpp
@@ -834,6 +834,8 @@ int
 yyparse()
 {
     register int yym, yyn, yystate;
+    char semsg[] = "syntax error";
+    char ysomsg[] = "yacc stack overflow";
 #if YYDEBUG
     register char *yys;
     extern char *getenv();
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
