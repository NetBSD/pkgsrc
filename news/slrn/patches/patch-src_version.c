$NetBSD: patch-src_version.c,v 1.1 2018/09/21 14:27:37 wiz Exp $

Added notes that this is a modified version.

--- src/version.c.orig	2016-10-23 22:34:16.000000000 +0000
+++ src/version.c
@@ -132,6 +132,11 @@ void slrn_show_version (FILE *fp) /*{{{*
    fprintf (fp, "slrn %s\n", Slrn_Version_String);
    if (*Slrn_Version_String == 'p')
      fprintf (fp, _("\t* Note: This version is a developer preview.\n"));
+
+   /* To be removed if patch is accepted upstream */
+   fprintf (fp, _("\t* Note: This is a modified version! (do not bother the author with questions)\n"));
+   fprintf (fp, _("\t* Patched to support libcanlock3 (see documentation)\n"));
+
    fprintf (fp, _("S-Lang Library Version: %s\n"), SLang_Version_String);
    if (SLANG_VERSION != SLang_Version)
      {
