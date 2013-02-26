$NetBSD: patch-src_read__rc.c,v 1.1 2013/02/26 11:08:17 joerg Exp $

--- src/read_rc.c.orig	2013-02-25 16:41:35.000000000 +0000
+++ src/read_rc.c
@@ -82,6 +82,7 @@ extern opts_menu *find_cfg_opts();
 static int lineno = 0;
 static int errors = 0;
 
+static void do_rc(FILE *file, int lcl);
 
 static void
 do_expand_env(descr, dest, src, destlen)
@@ -323,9 +324,7 @@ read_rc_file()
 }
 
 
-do_rc(file, lcl)
-FILE *file;
-int lcl;
+static void do_rc(FILE *file, int lcl)
 {
 	static int prev_type = 0;
 	int x;
