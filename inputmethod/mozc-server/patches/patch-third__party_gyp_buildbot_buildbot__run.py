$NetBSD: patch-third__party_gyp_buildbot_buildbot__run.py,v 1.1 2013/04/29 09:52:18 ryoon Exp $

--- third_party/gyp/buildbot/buildbot_run.py.orig	2012-02-23 21:18:54.000000000 +0000
+++ third_party/gyp/buildbot/buildbot_run.py
@@ -74,6 +74,8 @@ def GypBuild():
     retcode += GypTestFormat('ninja')
     retcode += GypTestFormat('scons')
     retcode += GypTestFormat('make')
+  elif sys.platform == 'netbsd':
+    retcode += GypTestFormat('make')
   elif sys.platform == 'darwin':
     retcode += GypTestFormat('ninja')
     retcode += GypTestFormat('xcode')
