$NetBSD: patch-jupyter__client_connect.py,v 1.1 2021/10/09 23:20:24 gutteridge Exp $

Set sticky bit only on the directory.
https://github.com/jupyter/jupyter_client/pull/711/

--- jupyter_client/connect.py.orig	2021-03-14 00:34:45.000000000 +0000
+++ jupyter_client/connect.py
@@ -137,31 +137,20 @@ def write_connection_file(fname=None, sh
         f.write(json.dumps(cfg, indent=2))
 
     if hasattr(stat, 'S_ISVTX'):
-        # set the sticky bit on the file and its parent directory
-        # to avoid periodic cleanup
-        paths = [fname]
+        # set the sticky bit on the parent directory of the file
+        # to ensure only owner can remove it
         runtime_dir = os.path.dirname(fname)
         if runtime_dir:
-            paths.append(runtime_dir)
-        for path in paths:
-            permissions = os.stat(path).st_mode
+            permissions = os.stat(runtime_dir).st_mode
             new_permissions = permissions | stat.S_ISVTX
             if new_permissions != permissions:
                 try:
-                    os.chmod(path, new_permissions)
+                    os.chmod(runtime_dir, new_permissions)
                 except OSError as e:
-                    if e.errno == errno.EPERM and path == runtime_dir:
+                    if e.errno == errno.EPERM:
                         # suppress permission errors setting sticky bit on runtime_dir,
                         # which we may not own.
                         pass
-                    else:
-                        # failed to set sticky bit, probably not a big deal
-                        warnings.warn(
-                            "Failed to set sticky bit on %r: %s"
-                            "\nProbably not a big deal, but runtime files may be cleaned up periodically." % (path, e),
-                            RuntimeWarning,
-                        )
-
     return fname, cfg
 
 
