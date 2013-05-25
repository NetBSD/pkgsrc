$NetBSD: patch-jbsrc_lib_src_core_jb-main.c,v 1.1 2013/05/25 23:43:58 joerg Exp $

--- jbsrc/lib/src/core/jb-main.c.orig	2013-05-25 17:48:27.000000000 +0000
+++ jbsrc/lib/src/core/jb-main.c
@@ -161,8 +161,6 @@ jb_main (int argc,
 
   g_log_set_fatal_mask(G_LOG_DOMAIN, G_LOG_LEVEL_CRITICAL);
 
-  g_type_init();
-
   jb_topsrcdir = g_get_current_dir();
 
   jb_set_log_file("build/jb.log");
