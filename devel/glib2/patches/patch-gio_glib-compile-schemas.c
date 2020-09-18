$NetBSD: patch-gio_glib-compile-schemas.c,v 1.1 2020/09/18 11:18:29 wiz Exp $

gsettings-desktop-schemas uses deprecated paths and is not going to stop
anytime soon, see
https://gitlab.gnome.org/GNOME/gsettings-desktop-schemas/-/issues/27

--- gio/glib-compile-schemas.c.orig	2020-08-18 11:06:36.941520700 +0000
+++ gio/glib-compile-schemas.c
@@ -1232,6 +1232,7 @@ parse_state_start_schema (ParseState  *s
       return;
     }
 
+#if 0
   if (path && (g_str_has_prefix (path, "/apps/") ||
                g_str_has_prefix (path, "/desktop/") ||
                g_str_has_prefix (path, "/system/")))
@@ -1244,6 +1245,7 @@ parse_state_start_schema (ParseState  *s
       g_printerr ("%s\n", message);
       g_free (message);
     }
+#endif
 
   state->schema_state = schema_state_new (path, gettext_domain,
                                           extends, extends_name, list_of);
