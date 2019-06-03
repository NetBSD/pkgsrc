$NetBSD: patch-gio_gunixmounts.c,v 1.4 2019/06/03 23:09:29 maya Exp $

SunOS has sys/mntent.h but no mnt_opts.
XXX who else uses the sys/mntent.h case?
https://gitlab.gnome.org/GNOME/glib/merge_requests/890

--- gio/gunixmounts.c.orig	2019-05-03 13:43:28.000000000 +0000
+++ gio/gunixmounts.c
@@ -736,7 +736,7 @@ _g_get_unix_mounts (void)
                                              mntent.mnt_mountp,
                                              NULL,
                                              mntent.mnt_fstype,
-                                             mntent.mnt_opts,
+                                             mntent.mnt_mntopts,
                                              is_read_only);
 
       return_list = g_list_prepend (return_list, mount_entry);

