$NetBSD: patch-nasl_nasl__grammar.y,v 1.1 2013/08/20 13:08:29 wiz Exp $

Fix build with bison-3.0.

--- nasl/nasl_grammar.y.orig	2008-12-16 13:06:34.000000000 +0000
+++ nasl/nasl_grammar.y
@@ -1,4 +1,6 @@
-%pure_parser
+%pure-parser
+%parse-param {void *parm}
+%lex-param {void *parm}
 %expect 1
 %{
 /* Nessus Attack Scripting Language version 2
@@ -32,7 +34,7 @@
 #include "nasl_debug.h"
 #include "nasl_signature.h"
 
-static void naslerror(const char *);
+static void naslerror(void *, char const *);
 #define YYERROR_VERBOSE
 %}
 
@@ -470,7 +472,7 @@ glob: GLOBAL arg_decl 
 #include <stdlib.h>
 
 static void 
-naslerror(const char *s)
+naslerror(void *locp, char const *s)
 {
   fputs(s, stderr);
 }
