$NetBSD: patch-grub-core_osdep_generic_blocklist.c,v 1.1 2020/05/02 16:53:54 triaxx Exp $

* Fix implicit declaration of function grub_file_filter_disable_compression()
  (http://git.savannah.gnu.org/cgit/grub.git/commit/?id=dabdfa1)

--- grub-core/osdep/generic/blocklist.c.orig	2018-11-24 17:13:02.000000000 +0000
+++ grub-core/osdep/generic/blocklist.c
@@ -59,7 +59,7 @@ grub_install_get_blocklist (grub_device_
 
       grub_disk_cache_invalidate_all ();
 
-      file = grub_file_open (core_path_dev, GRUB_FILE_TYPE_NONE | FILE_TYPE_NO_DECOMPRESS);
+      file = grub_file_open (core_path_dev, GRUB_FILE_TYPE_NONE | GRUB_FILE_TYPE_NO_DECOMPRESS);
       if (file)
 	{
 	  if (grub_file_size (file) != core_size)
@@ -116,7 +116,7 @@ grub_install_get_blocklist (grub_device_
 
   grub_file_t file;
   /* Now read the core image to determine where the sectors are.  */
-  file = grub_file_open (core_path_dev, GRUB_FILE_TYPE_NONE | FILE_TYPE_NO_DECOMPRESS);
+  file = grub_file_open (core_path_dev, GRUB_FILE_TYPE_NONE | GRUB_FILE_TYPE_NO_DECOMPRESS);
   if (! file)
     grub_util_error ("%s", grub_errmsg);
 
