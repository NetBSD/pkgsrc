$NetBSD: patch-gio_gunixmounts.c,v 1.6 2021/09/18 13:19:26 wiz Exp $

SunOS has sys/mntent.h but no mnt_opts.
XXX who else uses the sys/mntent.h case?
https://gitlab.gnome.org/GNOME/glib/merge_requests/890

getfsent does not support multiple threads, so use lock around its
use.
https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=250311
https://gitlab.gnome.org/GNOME/glib/-/merge_requests/1717

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
@@ -1406,6 +1406,8 @@ _g_get_unix_mount_points (void)
 
 #elif (defined(HAVE_GETVFSSTAT) || defined(HAVE_GETFSSTAT)) && defined(HAVE_FSTAB_H) && defined(HAVE_SYS_MOUNT_H)
 
+G_LOCK_DEFINE_STATIC(getfsent);
+
 static GList *
 _g_get_unix_mount_points (void)
 {
@@ -1417,9 +1419,6 @@ _g_get_unix_mount_points (void)
   struct stat sb;
 #endif
   
-  if (!setfsent ())
-    return NULL;
-
   return_list = NULL;
   
 #ifdef HAVE_SYS_SYSCTL_H
@@ -1450,6 +1449,11 @@ _g_get_unix_mount_points (void)
 #endif
 #endif
   
+  G_LOCK (getfsent);
+  if (!setfsent ()) {
+    G_UNLOCK (getfsent);
+    return NULL;
+  }
   while ((fstab = getfsent ()) != NULL)
     {
       gboolean is_read_only = FALSE;
@@ -1485,6 +1489,7 @@ _g_get_unix_mount_points (void)
     }
   
   endfsent ();
+  G_UNLOCK (getfsent);
   
   return g_list_reverse (return_list);
 }
