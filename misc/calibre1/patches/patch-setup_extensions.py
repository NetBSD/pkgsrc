$NetBSD: patch-setup_extensions.py,v 1.1 2015/02/08 00:32:35 wiz Exp $

Correct directory name.

--- setup/extensions.py.orig	2014-04-04 02:33:40.000000000 +0000
+++ setup/extensions.py
@@ -567,7 +567,7 @@ class Build(Command):
             self.check_call(qmc + ['qtcurve.pro'])
             self.check_call([make]+([] if iswindows else ['-j%d'%(cpu_count()
                 or 1)]))
-            src = (glob.glob('*.so') + glob.glob('release/*.dll') +
+            src = (glob.glob('.libs/*.so') + glob.glob('release/*.dll') +
                     glob.glob('*.dylib'))
             ext = 'pyd' if iswindows else 'so'
             if not os.path.exists(dest):
