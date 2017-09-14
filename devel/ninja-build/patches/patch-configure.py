$NetBSD: patch-configure.py,v 1.4 2017/09/14 08:23:53 adam Exp $

Add NetBSD support.

--- configure.py.orig	2017-09-11 01:20:10.000000000 +0000
+++ configure.py
@@ -98,7 +98,7 @@ class Platform(object):
         return self._platform == 'aix'
 
     def uses_usr_local(self):
-        return self._platform in ('freebsd', 'openbsd', 'bitrig', 'dragonfly')
+        return self._platform in ('freebsd', 'openbsd', 'bitrig', 'dragonfly', 'netbsd')
 
     def supports_ppoll(self):
         return self._platform in ('freebsd', 'linux', 'openbsd', 'bitrig',
@@ -354,8 +354,8 @@ else:
         cflags += ['-D_WIN32_WINNT=0x0501']
     ldflags = ['-L$builddir']
     if platform.uses_usr_local():
-        cflags.append('-I/usr/local/include')
-        ldflags.append('-L/usr/local/lib')
+        cflags.append('-I@PREFIX@/include')
+        ldflags.append('-L@PREFIX@/lib')
 
 libs = []
 
