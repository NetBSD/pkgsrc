$NetBSD: patch-lib_cftoken.l,v 1.2 2018/05/29 01:22:50 christos Exp $

Fixes for modern flex

--- lib/cftoken.l.orig	2018-05-28 17:21:27.733726555 -0400
+++ lib/cftoken.l	2018-05-28 17:21:57.559009640 -0400
@@ -53,7 +53,7 @@
 extern int yyget_lineno (void);
 extern FILE *yyget_in (void);
 extern FILE *yyget_out (void);
-extern int yyget_leng (void);
+extern yy_size_t yyget_leng (void);
 extern char *yyget_text (void);
 extern void yyset_lineno (int);
 extern void yyset_in (FILE *);
@@ -76,7 +76,7 @@
 #define YYDEBUG 1
 #define DP \
 	if (cf_debug) { \
-		fprintf(CF_ERRDEV, "%s:%d:%d[%s] len=%d\n", \
+		fprintf(CF_ERRDEV, "%s:%d:%d[%s] len=%zu\n", \
 		    rcf_istk[rcf_istkp].path, rcf_istk[rcf_istkp].lineno, \
 		    yy_start, yytext, yyleng); \
 	}
