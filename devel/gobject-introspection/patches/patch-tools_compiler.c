$NetBSD: patch-tools_compiler.c,v 1.1 2019/02/06 11:15:08 martin Exp $

Warnings should not be fatal
(see
devel/xfce4-conf/patches/patch-gsettings-backend_xfconf-giomodule.c for
an example why this may happen)

--- tools/compiler.c.orig	2017-05-13 15:19:04.000000000 +0200
+++ tools/compiler.c	2019-02-06 12:06:24.478613835 +0100
@@ -170,7 +170,7 @@ main (int argc, char ** argv)
     logged_levels = logged_levels | G_LOG_LEVEL_DEBUG;
   if (verbose)
     logged_levels = logged_levels | G_LOG_LEVEL_MESSAGE;
-  g_log_set_always_fatal (G_LOG_LEVEL_WARNING | G_LOG_LEVEL_CRITICAL);
+  g_log_set_always_fatal (G_LOG_LEVEL_CRITICAL);
 
   g_log_set_default_handler (log_handler, NULL);
 
