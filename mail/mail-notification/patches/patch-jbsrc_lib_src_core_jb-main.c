$NetBSD: patch-jbsrc_lib_src_core_jb-main.c,v 1.2 2014/08/21 13:21:33 jperkin Exp $

Support localedir.

--- jbsrc/lib/src/core/jb-main.c.orig	2008-04-27 14:47:28.000000000 +0000
+++ jbsrc/lib/src/core/jb-main.c
@@ -161,8 +161,6 @@ jb_main (int argc,
 
   g_log_set_fatal_mask(G_LOG_DOMAIN, G_LOG_LEVEL_CRITICAL);
 
-  g_type_init();
-
   jb_topsrcdir = g_get_current_dir();
 
   jb_set_log_file("build/jb.log");
@@ -237,6 +235,11 @@ jb_main (int argc,
 			 jb_variable_group_installation_options,
 			 0,
 			 "$prefix/libexec");
+  jb_variable_add_string("localedir",
+			 "locale directory",
+			 jb_variable_group_installation_options,
+			 0,
+			 "$prefix/share/locale");
   jb_variable_add_string("datadir",
 			 "read-only architecture-independent data directory",
 			 jb_variable_group_installation_options,
