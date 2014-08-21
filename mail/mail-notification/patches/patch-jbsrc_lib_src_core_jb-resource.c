$NetBSD: patch-jbsrc_lib_src_core_jb-resource.c,v 1.1 2014/08/21 13:21:33 jperkin Exp $

Support localedir.

--- jbsrc/lib/src/core/jb-resource.c.orig	2008-04-27 14:47:28.000000000 +0000
+++ jbsrc/lib/src/core/jb-resource.c
@@ -1443,7 +1443,7 @@ translations_install (JBResource *res)
 
   translations_get_files(self, NULL, &outfile);
 
-  installfile = g_strdup_printf("$prefix/share/locale/%s/LC_MESSAGES/$package.mo", self->lang);
+  installfile = g_strdup_printf("$localedir/%s/LC_MESSAGES/$package.mo", self->lang);
 
   jb_action_install_data_to_file(outfile, installfile);
 
