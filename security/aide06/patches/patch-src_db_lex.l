$NetBSD: patch-src_db_lex.l,v 1.1 2012/08/12 09:15:07 marino Exp $

--- src/db_lex.l.orig	1999-11-25 14:22:50.000000000 +0000
+++ src/db_lex.l
@@ -24,7 +24,7 @@ extern YYSTYPE yylval;
 #define YY_DECL int db_scan(void)
 
 
-#define YYDEBUG
+#define YYDEBUG 1
 
 #include "conf_yacc.h"
 #include <string.h>
