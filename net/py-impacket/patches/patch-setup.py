$NetBSD: patch-setup.py,v 1.2 2024/02/29 20:56:49 adam Exp $

Be consistent across platforms regarding data files.

--- setup.py.orig	2023-07-31 16:06:55.000000000 +0000
+++ setup.py
@@ -39,10 +39,7 @@ try:
 except Exception:
     VER_LOCAL = ""
 
-if platform.system() != 'Darwin':
-    data_files = [(os.path.join('share', 'doc', PACKAGE_NAME), ['README.md', 'LICENSE']+glob.glob('doc/*'))]
-else:
-    data_files = []
+data_files = []
 
 
 def read(fname):
