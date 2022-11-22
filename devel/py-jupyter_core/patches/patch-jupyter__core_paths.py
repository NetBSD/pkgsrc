$NetBSD: patch-jupyter__core_paths.py,v 1.3 2022/11/22 10:18:06 adam Exp $

Enable Jupyter to discover kernels installed by pkgsrc packages.

--- jupyter_core/paths.py.orig	2020-02-02 00:00:00.000000000 +0000
+++ jupyter_core/paths.py
@@ -188,6 +188,7 @@ else:
             SYSTEM_JUPYTER_PATH = [os.path.join(sys.prefix, "share", "jupyter")]
     else:
         SYSTEM_JUPYTER_PATH = [
+            "@PREFIX@/share/jupyter",
             "/usr/local/share/jupyter",
             "/usr/share/jupyter",
         ]
