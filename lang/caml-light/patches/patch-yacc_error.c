$NetBSD: patch-yacc_error.c,v 1.2 2015/12/29 23:34:44 dholland Exp $

Avoid implicit int.

--- yacc/error.c.orig	2012-10-20 13:06:22.000000000 +0000
+++ yacc/error.c
@@ -34,7 +34,7 @@ unexpected_EOF()
 }
 
 
-print_pos(st_line, st_cptr)
+void print_pos(st_line, st_cptr)
 char *st_line;
 char *st_cptr;
 {
