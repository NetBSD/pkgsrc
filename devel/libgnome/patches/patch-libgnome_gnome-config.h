$NetBSD: patch-libgnome_gnome-config.h,v 1.1 2017/10/19 09:14:32 jperkin Exp $

Remove UTF-8 characters that glib-mkenums does not like.

--- libgnome/gnome-config.h.orig	2009-04-23 09:29:13.000000000 +0000
+++ libgnome/gnome-config.h
@@ -270,7 +270,7 @@ void gnome_config_clean_key_ (const char
 #define gnome_config_private_clean_key(path) \
 	(gnome_config_clean_key_((path),TRUE))
 
-/* returns the true filename of the config file */
+/* returns the true filename of the config file */
 #define gnome_config_get_real_path(path) \
 	(g_build_filename (gnome_user_dir_get(),(path),NULL))
 #define gnome_config_private_get_real_path(path) \
