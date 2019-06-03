$NetBSD: patch-gio_gunixmounts.c,v 1.3 2019/06/03 21:24:04 maya Exp $

SunOS has sys/mntent.h but no mnt_opts.
XXX who else uses the sys/mntent.h case?

--- gio/gunixmounts.c.orig	2019-05-03 13:43:28.000000000 +0000
+++ gio/gunixmounts.c
@@ -736,7 +736,7 @@ _g_get_unix_mounts (void)
                                              mntent.mnt_mountp,
                                              NULL,
                                              mntent.mnt_fstype,
-                                             mntent.mnt_opts,
+                                             NULL/*mntent.mnt_opts*/,
                                              is_read_only);
 
       return_list = g_list_prepend (return_list, mount_entry);

