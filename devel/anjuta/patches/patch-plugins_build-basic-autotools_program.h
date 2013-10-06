$NetBSD: patch-plugins_build-basic-autotools_program.h,v 1.1 2013/10/06 20:01:27 joerg Exp $

--- plugins/build-basic-autotools/program.h.orig	2013-08-09 00:30:17.000000000 +0000
+++ plugins/build-basic-autotools/program.h
@@ -39,7 +39,7 @@ struct _BuildProgram
 };
 
 BuildProgram* build_program_new (void);
-BuildProgram* build_program_new_with_command (GFile *directory, const gchar *command,...);
+BuildProgram* build_program_new_with_command (GFile *directory, const gchar *command,...) G_GNUC_PRINTF(2,3);
 void build_program_free (BuildProgram *proc);
 
 gboolean build_program_set_command (BuildProgram *proc, const gchar *command);
