$NetBSD: patch-CodeLite_pp.cpp,v 1.2 2023/11/02 12:04:02 nros Exp $

Fix Warning: ISO C++ forbids converting a string constant to char*

--- CodeLite/pp.cpp.orig	2023-10-26 10:47:53.400757236 +0000
+++ CodeLite/pp.cpp
@@ -305,6 +305,8 @@ int
 yyparse()
 {
     register int yym, yyn, yystate;
+    char semsg[] = "syntax error";
+    char ysomsg[] = "yacc stack overflow";
 #if YYDEBUG
     register char *yys;
     extern char *getenv();
@@ -370,7 +372,7 @@ yyloop:
     goto yynewerror;
 #endif
 yynewerror:
-    yyerror("syntax error");
+    yyerror(semsg);
 #ifdef lint
     goto yyerrlab;
 #endif
@@ -577,7 +579,7 @@ to state %d\n", YYPREFIX, *yyssp, yystat
     *++yyvsp = yyval;
     goto yyloop;
 yyoverflow:
-    yyerror("yacc stack overflow");
+    yyerror(ysomsg);
 yyabort:
     return (1);
 yyaccept:
