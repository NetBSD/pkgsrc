$NetBSD: patch-cli-parse.yy,v 1.1 2011/09/08 00:12:00 joerg Exp $

--- cli/parse.yy.orig	2011-09-07 13:21:44.000000000 +0000
+++ cli/parse.yy
@@ -84,7 +84,7 @@ extern command *getLastKnownCommand();
 extern void init_cmd_state();
 extern const char * GetLastFullCommand();
 
-void yyerror(char *message)
+void yyerror(const char *message)
 {
   printf("***ERROR: %s while parsing:\n'%s'\n",message, yytext);
   const char *last = GetLastFullCommand();
