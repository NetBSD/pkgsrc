$NetBSD: patch-setup.py,v 1.1 2014/07/21 07:57:21 dbj Exp $
This software contains darwin specific tweaks which do not apply to pkgsrc

--- setup.py.orig	2012-12-24 08:00:57.000000000 +0000
+++ setup.py
@@ -141,9 +141,7 @@ def nuke_manifest(*files):
         print >>f, fn
     f.close()
                     
-if sys.platform == "darwin":
-    macos_build()
-elif sys.platform == "win32":
+if sys.platform == "win32":
     win32_build()
 else:
     if os.path.exists("rpttool"):
