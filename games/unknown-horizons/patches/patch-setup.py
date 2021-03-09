$NetBSD: patch-setup.py,v 1.2 2021/03/09 09:39:11 nia Exp $

- On NetBSD platform.dist() is not defined. Always install to
  the same binary directory anyway, for consistency.
- Install man pages to PKGMANDIR.

--- setup.py.orig	2019-01-12 15:15:42.000000000 +0000
+++ setup.py
@@ -39,10 +39,7 @@ from horizons.ext import polib
 # Ensure we are in the correct directory
 os.chdir(os.path.realpath(os.path.dirname(__file__)))
 
-if platform.dist()[0].lower() in ('debian', 'ubuntu'):
-	executable_path = 'games'
-else:
-	executable_path = 'bin'
+executable_path = 'bin'
 
 
 # this trick is for setting RELEASE_VERSION if the code is cloned from git repository
@@ -54,7 +51,7 @@ data = [
   (executable_path, ('unknown-horizons', )),
   ('share/pixmaps', ('content/packages/unknown-horizons.xpm', )),
   ('share/unknown-horizons', ('content/settings-template.xml', )),
-  ('share/man/man6', ('content/packages/unknown-horizons.6', )),
+  ('@PKGMANDIR@/man6', ('content/packages/unknown-horizons.6', )),
 ]
 
 for root, dirs, files in [x for x in os.walk('content') if len(x[2])]:
