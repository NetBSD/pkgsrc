$NetBSD: patch-cli-scan.ll,v 1.2 2020/04/20 00:36:45 joerg Exp $

--- cli/scan.ll.orig	2005-08-31 14:46:34.000000000 +0000
+++ cli/scan.ll
@@ -46,7 +46,7 @@ Boston, MA 02111-1307, USA.  */
 
 /* Since our parser is reentrant, it needs to pass us a pointer
  * to the yylval that it would like us to use */
-#define YY_DECL int yylex YY_PROTO(( YYSTYPE* yylvalP ))
+#define YY_DECL int yylex(YYSTYPE* yylvalP)
 extern int yyparse(void);
 
 /* This is the max length of a line within a macro definition */
@@ -760,9 +760,9 @@ static int process_stringLiteral(YYSTYPE
 
 static int process_quotedStringLiteral(YYSTYPE* yylvalP, const char *buffer)
 {
-  char * pCloseQuote = strchr(buffer, '\"');
-  *pCloseQuote = 0;
-  yylvalP->String_P = new String(buffer);
+  const char * pCloseQuote = strchr(buffer, '\"');
+  yylvalP->String_P = new String(0);
+  yylvalP->String_P->set(buffer, pCloseQuote - buffer);
   return(recognize(LITERAL_STRING_T, "string literal"));
 }
 
