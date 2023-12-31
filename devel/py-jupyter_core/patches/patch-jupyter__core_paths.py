$NetBSD: patch-jupyter__core_paths.py,v 1.4 2023/12/31 09:01:21 adam Exp $

Enable Jupyter to discover kernels installed by pkgsrc packages.

--- jupyter_core/paths.py.orig	2020-02-02 00:00:00.000000000 +0000
+++ jupyter_core/paths.py
@@ -222,6 +222,7 @@ else:
             SYSTEM_JUPYTER_PATH = [str(Path(sys.prefix, "share", "jupyter"))]
     else:
         SYSTEM_JUPYTER_PATH = [
+            "@PREFIX@/share/jupyter",
             "/usr/local/share/jupyter",
             "/usr/share/jupyter",
         ]
