$NetBSD: patch-setup_extensions.py,v 1.5 2015/02/08 00:37:10 wiz Exp $

Fix build for pictureflow.

--- setup/extensions.py.orig	2014-08-29 03:59:29.000000000 +0000
+++ setup/extensions.py
@@ -602,7 +602,7 @@ class Build(Command):
         if iswindows:
             qmc += ['-spec', 'win32-msvc2008']
         fext = 'dll' if iswindows else 'dylib' if isosx else 'so'
-        name = '%s%s.%s' % ('release/' if iswindows else 'lib', sip['target'], fext)
+        name = '%s%s.%s' % ('release/' if iswindows else '.libs/lib', sip['target'], fext)
         try:
             os.chdir(src_dir)
             if self.newer(dest, sip['headers'] + sip['sources'] + ext.sources + ext.headers):
