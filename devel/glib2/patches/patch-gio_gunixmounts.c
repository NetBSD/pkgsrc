$NetBSD: patch-gio_gunixmounts.c,v 1.8 2024/10/22 09:50:38 adam Exp $

SunOS has sys/mntent.h but no mnt_opts.
XXX who else uses the sys/mntent.h case?
https://gitlab.gnome.org/GNOME/glib/merge_requests/890

--- gio/gunixmounts.c.orig	2024-10-17 11:08:41.000000000 +0000
+++ gio/gunixmounts.c
@@ -835,7 +835,7 @@ _g_unix_mounts_get_from_file (const char
                                              mntent.mnt_mountp,
                                              NULL,
                                              mntent.mnt_fstype,
-                                             mntent.mnt_opts,
+                                             mntent.mnt_mntopts,
                                              is_read_only);
 
       g_ptr_array_add (return_array, g_steal_pointer (&mount_entry));
