$NetBSD: patch-tools_generate.c,v 1.1 2019/02/06 11:15:08 martin Exp $

Warnings should not be fatal
(see
devel/xfce4-conf/patches/patch-gsettings-backend_xfconf-giomodule.c for
an example why this may happen)

--- tools/generate.c.orig	2017-05-13 15:19:04.000000000 +0200
+++ tools/generate.c	2019-02-06 12:06:24.479367427 +0100
@@ -52,7 +52,7 @@ main (int argc, char *argv[])
       { NULL, }
     };
 
-  g_log_set_always_fatal (G_LOG_LEVEL_WARNING | G_LOG_LEVEL_CRITICAL);
+  g_log_set_always_fatal (G_LOG_LEVEL_CRITICAL);
 
   g_typelib_check_sanity ();
 
