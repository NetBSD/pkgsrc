$NetBSD: patch-barman_utils.py,v 1.2 2016/03/04 16:55:45 fhajny Exp $

Make portable for non-glibc platforms too.
--- barman/utils.py.orig	2016-02-22 08:01:31.000000000 +0000
+++ barman/utils.py
@@ -253,7 +253,7 @@ def fsync_dir(dir_path):
     :param str dir_path: The directory to sync
     :raise OSError: If fail opening the directory
     """
-    dir_fd = os.open(dir_path, os.O_DIRECTORY)
+    dir_fd = os.open(dir_path, os.O_RDONLY)
     try:
         os.fsync(dir_fd)
     except OSError as e:
