$NetBSD: patch-lib_grammar.y,v 1.1 2025/04/28 19:54:18 tnn Exp $

https://github.com/hyperrealm/libconfig/commit/690342b9cbc8b39787a1501bd890d63ca63a003c.patch

--- lib/grammar.y.orig	2019-12-15 04:49:27.000000000 +0000
+++ lib/grammar.y
@@ -40,8 +40,7 @@
 #include "wincompat.h"
 
 /* These declarations are provided to suppress compiler warnings. */
-extern int libconfig_yylex();
-extern int libconfig_yyget_lineno();
+extern int libconfig_yyget_lineno(void *);
 
 static const char *err_array_elem_type = "mismatched element type in array";
 static const char *err_duplicate_setting = "duplicate setting name";
@@ -80,6 +79,11 @@ void libconfig_yyerror(void *scanner, st
   char *sval;
 }
 
+%{
+/* These declarations are provided to suppress compiler warnings. */
+extern int libconfig_yylex(YYSTYPE *, void *);
+%}
+
 %token <ival> TOK_BOOLEAN TOK_INTEGER TOK_HEX
 %token <llval> TOK_INTEGER64 TOK_HEX64
 %token <fval> TOK_FLOAT
