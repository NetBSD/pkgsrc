$NetBSD: patch-filters_filters.h,v 1.2 2013/06/22 22:12:42 dholland Exp $

--- filters/filters.h.orig	2013-05-25 20:14:11.000000000 +0000
+++ filters/filters.h
@@ -210,7 +210,9 @@ extern FILE *yyget_in (void);
 extern FILE *yyget_out (void);
 extern char *yyget_text (void);
 extern int yyget_debug (void);
+#if 0
 extern int yyget_leng (void);
+#endif
 extern int yyget_lineno (void);
 extern int yylex_destroy (void);
 extern void yyset_debug (int bdebug);
