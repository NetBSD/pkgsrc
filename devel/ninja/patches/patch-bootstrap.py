$NetBSD: patch-bootstrap.py,v 1.1 2014/07/19 09:01:23 ryoon Exp $

* pkgsrc installation

--- bootstrap.py.orig	2014-06-27 23:37:05.000000000 +0000
+++ bootstrap.py
@@ -58,6 +58,9 @@ ldflags = os.environ.get('LDFLAGS', '').
 if platform.is_freebsd() or platform.is_openbsd() or platform.is_bitrig():
     cflags.append('-I/usr/local/include')
     ldflags.append('-L/usr/local/lib')
+if platform.is_netbsd():
+    cflags.append('-I@PREFIX@/include')
+    ldflags.append('-L@PREFIX@/lib')
 
 print('Building ninja manually...')
 
