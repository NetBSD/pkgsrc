$NetBSD: patch-setup_extensions.py,v 1.6 2015/12/30 00:08:33 wiz Exp $

Fix build for pictureflow.

--- setup/extensions.py.orig	2015-12-21 03:57:33.000000000 +0000
+++ setup/extensions.py
@@ -636,7 +636,7 @@ class Build(Command):
         if iswindows:
             qmc += ['-spec', qmakespec]
         fext = 'dll' if iswindows else 'dylib' if isosx else 'so'
-        name = '%s%s.%s' % ('release/' if iswindows else 'lib', sip['target'], fext)
+        name = '%s%s.%s' % ('release/' if iswindows else '.libs/lib', sip['target'], fext)
         try:
             os.chdir(src_dir)
             if self.newer(dest, sip['headers'] + sip['sources'] + ext.sources + ext.headers):
