$NetBSD: patch-src_editor_syntax.c,v 1.1 2012/12/19 16:00:21 joerg Exp $

--- src/editor/syntax.c.orig	2012-12-19 14:04:18.000000000 +0000
+++ src/editor/syntax.c
@@ -1079,7 +1079,7 @@ edit_read_syntax_file (WEdit * edit, cha
 
     f = fopen (syntax_file, "r");
     if (!f){
-	lib_file = concat_dir_and_file (mc_home, "Syntax");
+	lib_file = concat_dir_and_file (mc_home, "syntax" PATH_SEP_STR "Syntax");
 	f = fopen (lib_file, "r");
 	g_free (lib_file);
 	if (!f)
