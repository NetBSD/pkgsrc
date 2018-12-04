$NetBSD: patch-pdftexdir_writeenc.c,v 1.1 2018/12/04 13:01:44 ryoon Exp $

--- pdftexdir/writeenc.c.orig	2016-11-25 18:24:37.000000000 +0000
+++ pdftexdir/writeenc.c
@@ -83,7 +83,7 @@ fe_entry *get_fe_entry(char *s)
 
 /**********************************************************************/
 
-void epdf_write_enc(char **glyph_names, int fe_objnum)
+void epdf_write_enc(const char **glyph_names, int fe_objnum)
 {
     int i, i_old;
     assert(glyph_names != NULL);
