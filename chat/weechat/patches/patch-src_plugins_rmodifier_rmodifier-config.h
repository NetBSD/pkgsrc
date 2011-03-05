$NetBSD: patch-src_plugins_rmodifier_rmodifier-config.h,v 1.1 2011/03/05 22:48:07 tonio Exp $

Fix build for osx 10.5

--- src/plugins/rmodifier/rmodifier-config.h.orig	2011-01-01 14:45:46.000000000 +0000
+++ src/plugins/rmodifier/rmodifier-config.h
@@ -25,7 +25,7 @@
 extern struct t_config_file *rmodifier_config_file;
 extern struct t_config_section *rmodifier_config_section_modifier;
 
-struct t_config_option *rmodifier_config_look_hide_char;
+extern struct t_config_option *rmodifier_config_look_hide_char;
 
 extern char *rmodifier_config_default_list[][4];
 
