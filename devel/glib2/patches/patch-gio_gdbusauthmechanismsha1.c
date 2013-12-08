$NetBSD: patch-gio_gdbusauthmechanismsha1.c,v 1.2 2013/12/08 13:08:59 prlw1 Exp $

Suppress format warnings that are converted to errors with gcc 4.8

--- gio/gdbusauthmechanismsha1.c.orig	2013-08-08 10:00:40.000000000 +0000
+++ gio/gdbusauthmechanismsha1.c
@@ -273,7 +273,7 @@ ensure_keyring_directory (GError **error
                            G_IO_ERROR_FAILED,
                            _("Permissions on directory '%s' are malformed. Expected mode 0700, got 0%o"),
                            path,
-                           statbuf.st_mode & 0777);
+                           (guint)statbuf.st_mode & 0777);
               g_free (path);
               path = NULL;
               goto out;
