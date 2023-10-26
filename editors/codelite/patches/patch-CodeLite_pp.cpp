$NetBSD: patch-CodeLite_pp.cpp,v 1.1 2023/10/26 10:46:58 nros Exp $

Fix Warning: ISO C++ forbids converting a string constant to char*

--- CodeLite/pp.cpp.orig	2023-10-25 17:36:29.887514094 +0000
+++ CodeLite/pp.cpp
@@ -79,6 +79,8 @@ extern wxString g_filename;
 
 /* Static*/
 static std::vector<wxString> g_tmpMacros;
+static char semsg[] = "syntax error";
+static char ysomsg[] = "yacc stack overflow";
 
 /*************** Standard ytab.c continues here *********************/
 #define PP_DEFINE 257
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
