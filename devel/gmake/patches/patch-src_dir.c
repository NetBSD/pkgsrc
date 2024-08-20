$NetBSD: patch-src_dir.c,v 1.1 2024/08/20 07:07:53 mrg Exp $

readdir(3) does not change errno if it fails due to end-of-directory, so
must set errno = 0 before hand, if using it for this check.

--- src/dir.c.orig	2023-01-11 16:53:26.000000000 -0800
+++ src/dir.c	2024-08-20 00:00:46.979555824 -0700
@@ -730,6 +730,7 @@
       struct dirfile dirfile_key;
       struct dirfile **dirfile_slot;
 
+      errno = 0;
       ENULLLOOP (d, readdir (dc->dirstream));
       if (d == NULL)
         {
