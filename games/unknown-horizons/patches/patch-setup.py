$NetBSD: patch-setup.py,v 1.1 2019/08/07 12:07:35 nia Exp $

Install man pages to PKGMANDIR.

--- setup.py.orig	2019-01-12 15:15:42.000000000 +0000
+++ setup.py
@@ -54,7 +54,7 @@ data = [
   (executable_path, ('unknown-horizons', )),
   ('share/pixmaps', ('content/packages/unknown-horizons.xpm', )),
   ('share/unknown-horizons', ('content/settings-template.xml', )),
-  ('share/man/man6', ('content/packages/unknown-horizons.6', )),
+  ('@PKGMANDIR@/man6', ('content/packages/unknown-horizons.6', )),
 ]
 
 for root, dirs, files in [x for x in os.walk('content') if len(x[2])]:
