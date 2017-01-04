$NetBSD: patch-tools_wrc_parser.l,v 1.1 2017/01/04 11:52:24 jperkin Exp $

Ensure the local yywrap is used.

--- tools/wrc/parser.l.orig	2014-01-10 20:37:29.000000000 +0000
+++ tools/wrc/parser.l
@@ -119,6 +119,7 @@ cident	[a-zA-Z_][0-9a-zA-Z_]*
 #include "newstruc.h"
 
 #include "parser.tab.h"
+#undef yywrap
 
 /* Always update the current character position within a line */
 #define YY_USER_ACTION	char_number+=yyleng; wanted_id = want_id; want_id = 0;
