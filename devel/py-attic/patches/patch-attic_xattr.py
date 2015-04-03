$NetBSD: patch-attic_xattr.py,v 1.1 2015/04/03 09:43:47 wiz Exp $

Make xattr support optional.
https://github.com/jborg/attic/pull/235

--- attic/xattr.py.orig	2014-12-14 13:28:33.000000000 +0000
+++ attic/xattr.py
@@ -8,10 +8,10 @@ from ctypes import CDLL, create_string_b
 from ctypes.util import find_library
 
 
-def is_enabled():
+def is_enabled(path=None):
     """Determine if xattr is enabled on the filesystem
     """
-    with tempfile.NamedTemporaryFile() as fd:
+    with tempfile.NamedTemporaryFile(dir=path) as fd:
         try:
             setxattr(fd.fileno(), 'user.name', b'value')
         except OSError:
@@ -248,4 +248,14 @@ elif sys.platform.startswith('freebsd'):
         _check(func(path, EXTATTR_NAMESPACE_USER, name, value, len(value) if value else 0), path)
 
 else:
-    raise Exception('Unsupported platform: %s' % sys.platform)
+    # this is a dummy xattr interface for platforms for which we do not have
+    # a real implementation (or which do not support xattr at all).
+
+    def listxattr(path, *, follow_symlinks=True):
+        return []
+
+    def getxattr(path, name, *, follow_symlinks=True):
+        return
+
+    def setxattr(path, name, value, *, follow_symlinks=True):
+        return
