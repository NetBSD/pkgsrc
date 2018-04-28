$NetBSD: patch-src_python_grpcio_commands.py,v 1.1 2018/04/28 01:16:29 minskim Exp $

Use dependencies in pkgsrc.

--- src/python/grpcio/commands.py.orig	2018-04-05 20:19:07.000000000 +0000
+++ src/python/grpcio/commands.py
@@ -253,7 +253,7 @@ class BuildExt(build_ext.build_ext):
     LINK_OPTIONS = {}
 
     def build_extensions(self):
-        if "darwin" in sys.platform:
+        if False and "darwin" in sys.platform:
             config = os.environ.get('CONFIG', 'opt')
             target_path = os.path.abspath(
                 os.path.join(
