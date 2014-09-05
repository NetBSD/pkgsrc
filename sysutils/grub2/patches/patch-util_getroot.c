$NetBSD: patch-util_getroot.c,v 1.1 2014/09/05 12:14:24 gsutre Exp $

Fix grub-emu build.

* exec_pipe: Define only on Linux or when either libzfs or libnvpair is unavailable.
* find_root_devices_from_poolname: Remove unused path variable.

Taken from upstream commit 794c8c33758792627113ae98ec495b9856960d92.

--- util/getroot.c.orig	2012-06-22 15:42:07.000000000 +0000
+++ util/getroot.c
@@ -220,6 +220,9 @@ xgetcwd (void)
 
 #if !defined (__MINGW32__) && !defined (__CYGWIN__) && !defined (__GNU__)
 
+#if (defined (__linux__) || \
+     !defined (HAVE_LIBZFS) || !defined (HAVE_LIBNVPAIR))
+
 static pid_t
 exec_pipe (char **argv, int *fd)
 {
@@ -258,6 +261,8 @@ exec_pipe (char **argv, int *fd)
     }
 }
 
+#endif
+
 static char **
 find_root_devices_from_poolname (char *poolname)
 {
@@ -269,7 +274,7 @@ find_root_devices_from_poolname (char *p
   zpool_handle_t *zpool;
   libzfs_handle_t *libzfs;
   nvlist_t *config, *vdev_tree;
-  nvlist_t **children, **path;
+  nvlist_t **children;
   unsigned int nvlist_count;
   unsigned int i;
   char *device = 0;
