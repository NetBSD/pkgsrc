$NetBSD: patch-barman_backup.py,v 1.2 2015/04/07 09:42:55 fhajny Exp $

Make portable for non-glibc platforms too.
--- barman/backup.py.orig	2015-01-23 13:23:54.000000000 +0000
+++ barman/backup.py
@@ -1043,7 +1043,7 @@ class BackupManager(object):
         deduplicated_size = 0
         for dirpath, _, filenames in os.walk(backup_dest):
             # execute fsync() on the containing directory
-            dir_fd = os.open(dirpath, os.O_DIRECTORY)
+            dir_fd = os.open(dirpath, os.O_RDONLY)
             try:
                 os.fsync(dir_fd)
             except OSError, e:
@@ -1302,7 +1302,7 @@ class BackupManager(object):
             shutil.move(srcfile, destfile)
 
         # execute fsync() on the archived WAL containing directory
-        dir_fd = os.open(destdir, os.O_DIRECTORY)
+        dir_fd = os.open(destdir, os.O_RDONLY)
         try:
             os.fsync(dir_fd)
         except OSError, e:
