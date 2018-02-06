$NetBSD: patch-jupyter__core_paths.py,v 1.1 2018/02/06 01:40:48 minskim Exp $

Enable Jupyter to discover kernels installed by pkgsrc packages.

--- jupyter_core/paths.py.orig	2017-10-11 14:52:06.000000000 +0000
+++ jupyter_core/paths.py
@@ -118,6 +118,7 @@ if os.name == 'nt':
         SYSTEM_JUPYTER_PATH = [os.path.join(sys.prefix, 'share', 'jupyter')]
 else:
     SYSTEM_JUPYTER_PATH = [
+        "@PREFIX@/share/jupyter",
         "/usr/local/share/jupyter",
         "/usr/share/jupyter",
     ]
