$NetBSD: patch-jupyter__core_paths.py,v 1.2 2022/04/19 11:34:27 adam Exp $

Enable Jupyter to discover kernels installed by pkgsrc packages.

--- jupyter_core/paths.py.orig	2022-04-18 10:53:22.000000000 +0000
+++ jupyter_core/paths.py
@@ -131,6 +131,7 @@ if os.name == "nt":
         SYSTEM_JUPYTER_PATH = [os.path.join(sys.prefix, "share", "jupyter")]
 else:
     SYSTEM_JUPYTER_PATH = [
+        "@PREFIX@/share/jupyter",
         "/usr/local/share/jupyter",
         "/usr/share/jupyter",
     ]
