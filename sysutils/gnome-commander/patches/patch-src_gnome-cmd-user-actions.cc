$NetBSD: patch-src_gnome-cmd-user-actions.cc,v 1.1 2013/04/27 23:07:35 joerg Exp $

--- src/gnome-cmd-user-actions.cc.orig	2013-04-27 22:44:06.000000000 +0000
+++ src/gnome-cmd-user-actions.cc
@@ -1130,7 +1130,7 @@ void command_root_mode (GtkMenuItem *men
     argv[i++] = su;
     if (need_c)
         argv[i++] = "-c";
-    argv[i++] = g_get_prgname ();
+    argv[i++] = const_cast<char *>(g_get_prgname ());
     argv[i++] = NULL;
 
     GError *error = NULL;
