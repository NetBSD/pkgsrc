$NetBSD: patch-filters_filters.h,v 1.1 2013/05/25 23:42:45 joerg Exp $

--- filters/filters.h.orig	2013-05-25 20:14:11.000000000 +0000
+++ filters/filters.h
@@ -210,7 +210,7 @@ extern FILE *yyget_in (void);
 extern FILE *yyget_out (void);
 extern char *yyget_text (void);
 extern int yyget_debug (void);
-extern int yyget_leng (void);
+extern size_t yyget_leng (void);
 extern int yyget_lineno (void);
 extern int yylex_destroy (void);
 extern void yyset_debug (int bdebug);
