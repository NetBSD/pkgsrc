$NetBSD: patch-gio_gunixmounts.c,v 1.7 2022/10/06 13:34:07 adam Exp $

SunOS has sys/mntent.h but no mnt_opts.
XXX who else uses the sys/mntent.h case?
https://gitlab.gnome.org/GNOME/glib/merge_requests/890

--- gio/gunixmounts.c.orig	2021-08-19 15:27:25.722339900 +0000
+++ gio/gunixmounts.c
@@ -743,7 +743,7 @@ _g_get_unix_mounts (void)
                                              mntent.mnt_mountp,
                                              NULL,
                                              mntent.mnt_fstype,
-                                             mntent.mnt_opts,
+                                             mntent.mnt_mntopts,
                                              is_read_only);
 
       return_list = g_list_prepend (return_list, mount_entry);
