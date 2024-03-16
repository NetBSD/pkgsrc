$NetBSD: patch-source_modules.c,v 1.1 2024/03/16 13:11:55 nia Exp $

Fix duplicate symbols, via Fedora Linux.

--- source/modules.c.orig	2010-06-26 08:18:34.000000000 +0000
+++ source/modules.c
@@ -83,7 +83,7 @@ extern int (*dcc_output_func) (int, int,
 extern int (*dcc_input_func)  (int, int, char *, int, int);
 extern int (*dcc_close_func) (int, unsigned long, int);
 
-int (*serv_open_func) (int, unsigned long, int);
+extern int (*serv_open_func) (int, unsigned long, int);
 extern int (*serv_output_func) (int, int, char *, int);
 extern int (*serv_input_func)  (int, char *, int, int, int);
 extern int (*serv_close_func) (int, unsigned long, int);
