$NetBSD: patch-pdftexdir_writeenc.c,v 1.2 2019/05/14 13:23:10 adam Exp $

Fix building.

--- pdftexdir/writeenc.c.orig	2016-11-25 18:24:37.000000000 +0000
+++ pdftexdir/writeenc.c
@@ -83,7 +83,7 @@ fe_entry *get_fe_entry(char *s)
 
 /**********************************************************************/
 
-void epdf_write_enc(char **glyph_names, int fe_objnum)
+void epdf_write_enc(const char **glyph_names, int fe_objnum)
 {
     int i, i_old;
     assert(glyph_names != NULL);
