$NetBSD: patch-configure.py,v 1.2 2016/05/16 11:56:11 ryoon Exp $

* Add NetBSD support

--- configure.py.orig	2016-04-28 14:56:44.000000000 +0000
+++ configure.py
@@ -95,7 +95,7 @@ class Platform(object):
         return self._platform == 'aix'
 
     def uses_usr_local(self):
-        return self._platform in ('freebsd', 'openbsd', 'bitrig')
+        return self._platform in ('freebsd', 'openbsd', 'bitrig', 'netbsd')
 
     def supports_ppoll(self):
         return self._platform in ('linux', 'openbsd', 'bitrig')
@@ -350,8 +350,8 @@ else:
         cflags += ['-D_WIN32_WINNT=0x0501']
     ldflags = ['-L$builddir']
     if platform.uses_usr_local():
-        cflags.append('-I/usr/local/include')
-        ldflags.append('-L/usr/local/lib')
+        cflags.append('-I@PREFIX@/include')
+        ldflags.append('-L@PREFIX@/lib')
 
 libs = []
 
