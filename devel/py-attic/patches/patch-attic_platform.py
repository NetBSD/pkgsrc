$NetBSD: patch-attic_platform.py,v 1.1 2015/04/03 09:43:47 wiz Exp $

Make xattr support optional.
https://github.com/jborg/attic/pull/235

--- attic/platform.py.orig	2014-05-03 13:16:06.000000000 +0000
+++ attic/platform.py
@@ -9,9 +9,13 @@ elif platform == 'FreeBSD':
 elif platform == 'Darwin':
     from attic.platform_darwin import acl_get, acl_set, API_VERSION
 else:
-    API_VERSION = 1
+    # this is a dummy acl interface for platforms for which we do not have
+    # a real implementation (or which do not support acls at all).
 
-    def acl_get(path, item, numeric_owner=False):
+    API_VERSION = 2
+
+    def acl_get(path, item, st, numeric_owner=False):
         pass
+
     def acl_set(path, item, numeric_owner=False):
         pass
