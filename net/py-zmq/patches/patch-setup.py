$NetBSD: patch-setup.py,v 1.1 2012/03/02 18:44:45 apb Exp $

Use PREFIX/include and PREFIX/lib for pkgsrc build.

--- setup.py.orig	2011-10-12 22:38:44.000000000 +0000
+++ setup.py
@@ -126,6 +126,10 @@ else:
     if ZMQ is not None:
         COMPILER_SETTINGS['include_dirs'] += [pjoin(ZMQ, 'include')]
         COMPILER_SETTINGS['library_dirs'] += [pjoin(ZMQ, 'lib')]
+    elif os.environ['PREFIX']:
+        PREFIX = os.environ['PREFIX']
+        COMPILER_SETTINGS['include_dirs'] += [pjoin(PREFIX, 'include')]
+        COMPILER_SETTINGS['library_dirs'] += [pjoin(PREFIX, 'lib')]
     elif sys.platform == 'darwin' and os.path.isdir('/opt/local/lib'):
         # allow macports default
         COMPILER_SETTINGS['include_dirs'] += ['/opt/local/include']
