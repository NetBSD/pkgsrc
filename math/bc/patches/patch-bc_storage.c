$NetBSD: patch-bc_storage.c,v 1.1 2015/12/12 19:50:36 markd Exp $

--- bc/storage.c.orig	2006-09-05 02:39:31.000000000 +0000
+++ bc/storage.c
@@ -99,6 +99,7 @@ more_functions (VOID)
     {
       f = &functions[indx];
       f->f_defined = FALSE;
+      f->f_void = FALSE;
       f->f_body = (char *) bc_malloc (BC_START_SIZE);
       f->f_body_size = BC_START_SIZE;
       f->f_code_size = 0;
