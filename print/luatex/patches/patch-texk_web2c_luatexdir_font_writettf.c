$NetBSD: patch-texk_web2c_luatexdir_font_writettf.c,v 1.1 2023/05/24 12:03:35 markd Exp $

1.16.0 -> 1.17.0

--- texk/web2c/luatexdir/font/writettf.c	2023/05/01 23:50:21	66983
+++ texk/web2c/luatexdir/font/writettf.c	2023/05/02 15:26:43	66984
@@ -1518,7 +1518,7 @@ static void do_writeotf(PDF pdf, fd_entr
     if (tracefilenames)
         tex_printf("<<%s", cur_file_name);
     ttf_read_tabdir();
-    /*tex Read teh font parameters. */
+    /*tex Read the font parameters. */
     if (ttf_name_lookup("head", false) != NULL)
         ttf_read_head();
     if (ttf_name_lookup("hhea", false) != NULL)
@@ -1570,4 +1570,3 @@ void writeotf(PDF pdf, fd_entry * fd)
     xfree(ttf_buffer);
     cur_file_name = NULL;
 }
-
