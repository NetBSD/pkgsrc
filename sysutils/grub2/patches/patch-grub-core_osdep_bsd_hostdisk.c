$NetBSD: patch-grub-core_osdep_bsd_hostdisk.c,v 1.1 2018/05/23 07:56:53 triaxx Exp $

Fix build error for NetBSD:
 * undefined RAW_FLOPPY_MAJOR macro
 * undefined fd variable

--- grub-core/osdep/bsd/hostdisk.c.orig    2015-05-21 15:50:29.000000000 +0000
+++ grub-core/osdep/bsd/hostdisk.c
@@ -50,6 +50,9 @@
 # endif /* HAVE_GETRAWPARTITION */
 # if defined(__NetBSD__)
 # include <sys/fdio.h>
+# ifndef RAW_FLOPPY_MAJOR
+#  define RAW_FLOPPY_MAJOR 9
+# endif /* ! RAW_FLOPPY_MAJOR */
 # endif
 # if defined(__OpenBSD__)
 # include <sys/dkio.h>
@@ -61,7 +64,7 @@
    floppy driver from retrying operations on failure, as otherwise the
    driver takes a while to abort when there is no floppy in the drive.  */
 static void
-configure_device_driver (grub_util_fd_t fd)
+grub_hostdisk_configure_device_driver (grub_util_fd_t fd)
 {
   struct stat st;

@@ -81,7 +84,7 @@ configure_device_driver (grub_util_fd_t
 grub_util_fd_t
 grub_util_fd_open (const char *os_dev, int flags)
 {
-  grub_util_fd_t ret;
+  grub_util_fd_t fd;

 #ifdef O_LARGEFILE
   flags |= O_LARGEFILE;
@@ -90,10 +93,10 @@ grub_util_fd_open (const char *os_dev, i
   flags |= O_BINARY;
 #endif

-  ret = open (os_dev, flags, S_IROTH | S_IRGRP | S_IRUSR | S_IWUSR);
-  if (ret >= 0)
-    configure_device_driver (fd);
-  return ret;
+  fd = open (os_dev, flags, S_IROTH | S_IRGRP | S_IRUSR | S_IWUSR);
+  if (fd >= 0)
+    grub_hostdisk_configure_device_driver (fd);
+  return fd;
 }

 #endif
