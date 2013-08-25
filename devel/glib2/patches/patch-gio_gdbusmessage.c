$NetBSD: patch-gio_gdbusmessage.c,v 1.1 2013/08/25 08:39:12 richard Exp $

* suppress format warnings that are converted to errors with gcc 4.8
*
--- gio/gdbusmessage.c.orig	2013-08-07 14:36:32.000000000 +0000
+++ gio/gdbusmessage.c
@@ -3463,9 +3463,9 @@ g_dbus_message_print (GDBusMessage *mess
               if (fstat (fds[n], &statbuf) == 0)
                 {
                   g_string_append_printf (fs, "%s" "dev=%d:%d", fs->len > 0 ? "," : "",
-                                          major (statbuf.st_dev), minor (statbuf.st_dev));
+                                          (int)major (statbuf.st_dev), (int)minor (statbuf.st_dev));
                   g_string_append_printf (fs, "%s" "mode=0%o", fs->len > 0 ? "," : "",
-                                          statbuf.st_mode);
+                                          (guint)statbuf.st_mode);
                   g_string_append_printf (fs, "%s" "ino=%" G_GUINT64_FORMAT, fs->len > 0 ? "," : "",
                                           (guint64) statbuf.st_ino);
                   g_string_append_printf (fs, "%s" "uid=%d", fs->len > 0 ? "," : "",
@@ -3473,7 +3473,7 @@ g_dbus_message_print (GDBusMessage *mess
                   g_string_append_printf (fs, "%s" "gid=%d", fs->len > 0 ? "," : "",
                                           statbuf.st_gid);
                   g_string_append_printf (fs, "%s" "rdev=%d:%d", fs->len > 0 ? "," : "",
-                                          major (statbuf.st_rdev), minor (statbuf.st_rdev));
+                                          (int)major (statbuf.st_rdev), (int)minor (statbuf.st_rdev));
                   g_string_append_printf (fs, "%s" "size=%" G_GUINT64_FORMAT, fs->len > 0 ? "," : "",
                                           (guint64) statbuf.st_size);
                   g_string_append_printf (fs, "%s" "atime=%" G_GUINT64_FORMAT, fs->len > 0 ? "," : "",
