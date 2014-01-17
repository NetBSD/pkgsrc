$NetBSD: patch-lockfile_pidlockfile.py,v 1.1 2014/01/17 14:45:26 wiz Exp $

python-3.x compatibility.

--- lockfile/pidlockfile.py.orig	2010-09-19 13:39:17.000000000 +0000
+++ lockfile/pidlockfile.py
@@ -77,7 +77,7 @@ class PIDLockFile(LockBase):
         while True:
             try:
                 write_pid_to_pidfile(self.path)
-            except OSError, exc:
+            except OSError as exc:
                 if exc.errno == errno.EEXIST:
                     # The lock creation failed.  Maybe sleep a bit.
                     if timeout is not None and time.time() > end_time:
@@ -155,7 +155,7 @@ def write_pid_to_pidfile(pidfile_path):
 
         """
     open_flags = (os.O_CREAT | os.O_EXCL | os.O_WRONLY)
-    open_mode = 0644
+    open_mode = 0o644
     pidfile_fd = os.open(pidfile_path, open_flags, open_mode)
     pidfile = os.fdopen(pidfile_fd, 'w')
 
@@ -182,7 +182,7 @@ def remove_existing_pidfile(pidfile_path
         """
     try:
         os.remove(pidfile_path)
-    except OSError, exc:
+    except OSError as exc:
         if exc.errno == errno.ENOENT:
             pass
         else:
