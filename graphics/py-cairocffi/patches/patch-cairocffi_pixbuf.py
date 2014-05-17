$NetBSD: patch-cairocffi_pixbuf.py,v 1.1 2014/05/17 13:43:41 rodent Exp $

Fix shared library name search for non-{Linux,Windows} OSes.

--- cairocffi/pixbuf.py.orig	2013-07-01 18:17:16.000000000 +0000
+++ cairocffi/pixbuf.py
@@ -87,11 +87,13 @@ ffi.cdef('''
 
 ''')
 
-gdk_pixbuf = dlopen(ffi, 'gdk_pixbuf-2.0', 'libgdk_pixbuf-2.0-0')
-gobject = dlopen(ffi, 'gobject-2.0', 'libgobject-2.0-0')
-glib = dlopen(ffi, 'glib-2.0', 'libglib-2.0-0')
+gdk_pixbuf = dlopen(ffi, 'gdk_pixbuf-2.0', 'libgdk_pixbuf-2.0-0', 
+                    'libgdk_pixbuf-2.0.so')
+gobject = dlopen(ffi, 'gobject-2.0', 'libgobject-2.0-0', 'libgobject-2.0.so')
+glib = dlopen(ffi, 'glib-2.0', 'libglib-2.0-0', 'libglib-2.0.so')
 try:
-    gdk = dlopen(ffi, 'gdk-3', 'gdk-x11-2.0', 'libgdk-win32-2.0-0')
+    gdk = dlopen(ffi, 'gdk-3', 'gdk-x11-2.0', 'libgdk-win32-2.0-0', 
+                 'libgdk-x11-2.0.so')
 except OSError:
     gdk = None
 
