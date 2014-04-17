$NetBSD: patch-lib_bashline.h,v 1.1 2014/04/17 20:27:32 joerg Exp $

--- lib/bashline.h.orig	2014-04-17 18:30:40.000000000 +0000
+++ lib/bashline.h
@@ -15,7 +15,7 @@
 #define _bashline_h_included
 
 char *bash_quote_filename (char *s, int rtype, char *qcp);
-char *bash_dequote_filename (const char *text, int quote_char);
+char *bash_dequote_filename (char *text, int quote_char);
 char *bash_backslash_quote (char *string);
 char *bash_single_quote (char *string);
 char *bash_double_quote (char *string);
