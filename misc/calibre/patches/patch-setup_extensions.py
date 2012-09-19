$NetBSD: patch-setup_extensions.py,v 1.3 2012/09/19 15:38:27 ryoon Exp $

--- setup/extensions.py.orig	2012-09-19 15:19:07.000000000 +0000
+++ setup/extensions.py
@@ -483,7 +483,7 @@ class Build(Command):
             self.check_call(qmc + ['qtcurve.pro'])
             self.check_call([make]+([] if iswindows else ['-j%d'%(cpu_count()
                 or 1)]))
-            src = (glob.glob('*.so') + glob.glob('release/*.dll') +
+            src = (glob.glob('.libs/*.so') + glob.glob('release/*.dll') +
                     glob.glob('*.dylib'))
             ext = 'pyd' if iswindows else 'so'
             shutil.copy2(src[0], self.j(dest, 'calibre_style.'+ext))
