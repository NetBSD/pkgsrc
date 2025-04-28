$NetBSD: patch-gram.y,v 1.1 2025/04/28 19:15:19 tnn Exp $

Avoid conflict with C23 bool

--- gram.y.orig	2025-04-28 18:50:09.000956221 +0000
+++ gram.y
@@ -84,7 +84,7 @@ ParseNewSymbol (Publish publish, Class c
     SymbolPtr	    symbol;
     NamespacePtr    namespace;
     CodePtr	    code;
-    Bool	    bool;
+    Bool	    xbool;
     AtomListPtr	    atomList;
     FuncDecl	    funcDecl;
 }
@@ -121,7 +121,7 @@ ParseNewSymbol (Publish publish, Class c
 %type  <argDecl>    argdecl
 %type  <argType>    opt_argdefines argdefines args
 %type  <argDecl>    argdefine
-%type  <bool>	    opt_dotdotdot
+%type  <xbool>	    opt_dotdotdot
 
 %type  <expr>	    opt_expr for_exprs expr opt_exprs exprs simpleexpr
 %type  <expr>	    opt_actuals actuals
