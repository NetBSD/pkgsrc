$NetBSD: patch-configure.py,v 1.1 2015/08/29 06:32:02 wiz Exp $

* Add NetBSD support

--- configure.py.orig	2015-06-29 17:21:30.000000000 +0000
+++ configure.py
@@ -82,6 +82,9 @@ class Platform(object):
         out, err = popen.communicate()
         return '/FS ' in str(out)
 
+    def is_netbsd(self):
+        return self._platform == 'netbsd'
+
     def is_windows(self):
         return self.is_mingw() or self.is_msvc()
 
@@ -330,6 +333,9 @@ else:
     if platform.uses_usr_local():
         cflags.append('-I/usr/local/include')
         ldflags.append('-L/usr/local/lib')
+    if platform.is_netbsd():
+        cflags.append('-I@PREFIX@/include')
+        ldflags.append('-L@PREFIX@/lib')
 
 libs = []
 
