$NetBSD: patch-cli-scan.ll,v 1.1 2011/09/08 00:12:00 joerg Exp $

--- cli/scan.ll.orig	2011-09-07 13:25:35.000000000 +0000
+++ cli/scan.ll
@@ -46,7 +46,7 @@ Boston, MA 02111-1307, USA.  */
 
 /* Since our parser is reentrant, it needs to pass us a pointer
  * to the yylval that it would like us to use */
-#define YY_DECL int yylex YY_PROTO(( YYSTYPE* yylvalP ))
+#define YY_DECL int yylex(YYSTYPE* yylvalP)
 extern int yyparse(void);
 
 /* This is the max length of a line within a macro definition */
