$NetBSD: patch-src_extspec.c,v 1.1 2012/10/26 20:37:15 joerg Exp $

--- src/extspec.c.orig	2012-10-26 13:02:40.000000000 +0000
+++ src/extspec.c
@@ -473,10 +473,7 @@ found:
 /******************************************************************************
                                                         LESINN_EXTERNAL_SPEC */
 
-lesinn_external_spec (ident, filename, kind)
-     char *ident;
-     char *filename;
-     char kind;
+void lesinn_external_spec (char *ident, char *filename, char kind)
 {
   char *hprefquantident;
   struct BLOCK *hcblock;
@@ -562,8 +559,7 @@ static write_text_mif (f, s) FILE *f; un
 /******************************************************************************
                                                               WRITE_DECL_MIF */
 
-static write_decl_mif (f, rd, level)
-       FILE *f; struct DECL *rd; int level;
+static void write_decl_mif (FILE *f, struct DECL *rd, int level)
 {
   if (rd->kind == KBLOKK || rd->kind == KPRBLK || rd->kind == KFOR || 
       rd->kind == KINSP) return;
