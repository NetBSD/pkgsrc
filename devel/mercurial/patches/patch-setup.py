$NetBSD: patch-setup.py,v 1.1 2012/03/15 19:43:06 adam Exp $

Fix double splitlines(); affects builing on Mac OS X.

--- setup.py.orig	2012-03-15 19:37:26.000000000 +0000
+++ setup.py
@@ -452,7 +452,7 @@ if os.name == 'nt':
 if sys.platform == 'darwin' and os.path.exists('/usr/bin/xcodebuild'):
     # XCode 4.0 dropped support for ppc architecture, which is hardcoded in
     # distutils.sysconfig
-    version = runcmd(['/usr/bin/xcodebuild', '-version'], {})[0].splitlines()
+    version = runcmd(['/usr/bin/xcodebuild', '-version'], {})[0]
     if version:
         version = version.splitlines()[0]
         xcode4 = (version.startswith('Xcode') and
