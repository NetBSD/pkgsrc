$NetBSD: patch-barman_backup.py,v 1.1 2014/11/04 12:56:14 fhajny Exp $

Make portable for non-glibc platforms too.
--- barman/backup.py.orig	2014-08-14 16:10:43.000000000 +0000
+++ barman/backup.py
@@ -956,7 +956,7 @@ class BackupManager(object):
         backup_size = 0
         for dirpath, _, filenames in os.walk(backup_dest):
             # execute fsync() on the containing directory
-            dir_fd = os.open(dirpath, os.O_DIRECTORY)
+            dir_fd = os.open(dirpath, os.O_RDONLY)
             os.fsync(dir_fd)
             os.close(dir_fd)
             # execute fsync() on all the contained files
@@ -1166,7 +1166,7 @@ class BackupManager(object):
             shutil.move(filename, destfile)
 
         # execute fsync() on the archived WAL containing directory
-        dir_fd = os.open(os.path.dirname(destfile), os.O_DIRECTORY)
+        dir_fd = os.open(os.path.dirname(destfile), os.O_RDONLY)
         os.fsync(dir_fd)
         os.close(dir_fd)
         # execute fsync() on the archived WAL file
