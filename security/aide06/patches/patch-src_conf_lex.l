$NetBSD: patch-src_conf_lex.l,v 1.1 2012/08/12 09:15:07 marino Exp $

--- src/conf_lex.l.orig	2000-01-27 14:42:24.000000000 +0000
+++ src/conf_lex.l
@@ -12,7 +12,7 @@ EX      [" "\t]*
 
 %{
 
-#define YYDEBUG
+#define YYDEBUG 1
 
 #include <string.h>
 #include "conf_yacc.h"
