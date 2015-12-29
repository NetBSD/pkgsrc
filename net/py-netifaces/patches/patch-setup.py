$NetBSD: patch-setup.py,v 1.2 2015/12/29 04:04:30 dholland Exp $

Use the os specific libraries also for the test build, fixes SunOS

--- setup.py.orig	2012-01-31 11:24:29.000000000 +0000
+++ setup.py
@@ -40,7 +40,7 @@ class my_build_ext(build_ext):
         self.check_requirements()
         build_ext.build_extensions(self)
 
-    def test_build(self, contents, link=True, execute=False, libraries=None,
+    def test_build(self, contents, link=True, execute=False, libraries=libraries,
                    include_dirs=None, library_dirs=None):
         name = os.path.join(self.build_temp, 'conftest-%s.c' % self.conftestidx)
         self.conftestidx += 1
