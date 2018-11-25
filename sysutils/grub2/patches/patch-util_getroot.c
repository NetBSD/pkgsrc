$NetBSD: patch-util_getroot.c,v 1.3 2018/11/25 15:51:01 maya Exp $

Be consistent about macros. The required headers are only
included if both libzfs and libnvpair are detected.

--- util/getroot.c.orig	2017-04-24 09:16:00.000000000 +0000
+++ util/getroot.c
@@ -456,7 +456,7 @@ grub_util_biosdisk_is_present (const cha
   return ret;
 }
 
-#ifdef HAVE_LIBZFS
+#if defined(HAVE_LIBZFS) && defined(HAVE_LIBNVPAIR)
 static libzfs_handle_t *__libzfs_handle;
 
 static void
