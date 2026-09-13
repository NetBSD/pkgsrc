$NetBSD: patch-radicale_web.py,v 1.1 2026/09/13 13:07:39 jakllsch Exp $

Avoid using deprecated and removed pkg_resources

--- radicale/web.py.orig	2020-05-19 01:33:23.000000000 +0000
+++ radicale/web.py
@@ -19,8 +19,7 @@ import posixpath
 import time
 from http import client
 from importlib import import_module
-
-import pkg_resources
+from importlib import resources as importlib_resources
 
 from radicale import storage
 
@@ -92,12 +91,13 @@ class NoneWeb(BaseWeb):
 class Web(BaseWeb):
     def __init__(self, configuration, logger):
         super().__init__(configuration, logger)
-        self.folder = pkg_resources.resource_filename(__name__, "web")
+        self.folder = importlib_resources.files('radicale') / 'web'
 
     def get(self, environ, base_prefix, path, user):
         try:
-            filesystem_path = storage.path_to_filesystem(
-                self.folder, path[len("/.web"):])
+            with importlib_resources.as_file(self.folder) as mypath:
+                filesystem_path = storage.path_to_filesystem(
+                    mypath, path[len("/.web"):])
         except ValueError as e:
             self.logger.debug("Web content with unsafe path %r requested: %s",
                               path, e, exc_info=True)
