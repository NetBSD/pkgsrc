$NetBSD: patch-modules_access_file.c,v 1.1 2015/10/25 11:00:18 wiz Exp $

--- modules/access/file.c.orig	2014-11-16 18:57:58.000000000 +0000
+++ modules/access/file.c
@@ -42,6 +42,9 @@
 #ifdef HAVE_LINUX_MAGIC_H
 #   include <sys/vfs.h>
 #   include <linux/magic.h>
+#elif defined (HAVE_FSTATVFS)
+#   include <sys/statvfs.h>
+#   include <sys/mount.h>
 #endif
 
 #if defined( _WIN32 )
@@ -75,7 +78,7 @@ struct access_sys_t
 #if !defined (_WIN32) && !defined (__OS2__)
 static bool IsRemote (int fd)
 {
-#if defined (HAVE_FSTATVFS) && defined (MNT_LOCAL)
+#if !defined(__linux__) && defined (HAVE_FSTATVFS) && defined (MNT_LOCAL)
     struct statvfs stf;
 
     if (fstatvfs (fd, &stf))
