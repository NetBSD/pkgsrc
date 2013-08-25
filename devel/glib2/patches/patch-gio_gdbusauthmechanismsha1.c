$NetBSD: patch-gio_gdbusauthmechanismsha1.c,v 1.1 2013/08/25 08:39:12 richard Exp $

* suppress format warnings that are converted to errors with gcc 4.8
*
--- gio/gdbusauthmechanismsha1.c.orig	2013-08-07 14:34:32.000000000 +0000
+++ gio/gdbusauthmechanismsha1.c
@@ -277,7 +277,7 @@ ensure_keyring_directory (GError **error
                            G_IO_ERROR_FAILED,
                            _("Permissions on directory `%s' are malformed. Expected mode 0700, got 0%o"),
                            path,
-                           statbuf.st_mode & 0777);
+                           (guint)statbuf.st_mode & 0777);
               g_free (path);
               path = NULL;
               goto out;
