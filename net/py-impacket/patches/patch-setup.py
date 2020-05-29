$NetBSD: patch-setup.py,v 1.1 2020/05/29 06:04:32 adam Exp $

Be consistent across platforms regarding data files.

--- setup.py.orig	2020-05-29 06:02:18.000000000 +0000
+++ setup.py
@@ -31,10 +31,7 @@ try:
 except Exception:
     VER_LOCAL = ""
 
-if platform.system() != 'Darwin':
-    data_files = [(os.path.join('share', 'doc', PACKAGE_NAME), ['README.md', 'LICENSE']+glob.glob('doc/*'))]
-else:
-    data_files = []
+data_files = []
 
 def read(fname):
     return open(os.path.join(os.path.dirname(__file__), fname)).read()
