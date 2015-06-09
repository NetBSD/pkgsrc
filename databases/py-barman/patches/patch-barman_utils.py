$NetBSD: patch-barman_utils.py,v 1.1 2015/06/09 15:06:39 fhajny Exp $

Make portable for non-glibc platforms too.
--- barman/utils.py.orig	2015-04-17 13:05:38.000000000 +0000
+++ barman/utils.py
@@ -239,7 +239,7 @@ def fsync_dir(dir_path):
     :param str dir_path: The directory to sync
     :raise OSError: If fail opening the directory
     """
-    dir_fd = os.open(dir_path, os.O_DIRECTORY)
+    dir_fd = os.open(dir_path, os.O_RDONLY)
     try:
         os.fsync(dir_fd)
     except OSError, e:
