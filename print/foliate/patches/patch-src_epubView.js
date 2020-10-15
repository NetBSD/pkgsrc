$NetBSD: patch-src_epubView.js,v 1.4 2020/10/15 16:10:24 fox Exp $

Adds variable to help substitute the correct python version suffix.

--- src/epubView.js.orig	2020-10-15 00:52:44.000000000 +0000
+++ src/epubView.js
@@ -26,7 +26,7 @@ const {
     debounce
 } = imports.utils
 
-const python = GLib.find_program_in_path('python') || GLib.find_program_in_path('python3')
+const python = GLib.find_program_in_path('python@PYVERSSUFFIX@')
 const kindleUnpack = pkg.pkgdatadir + '/assets/KindleUnpack/kindleunpack.py'
 
 const settings = new Gio.Settings({ schema_id: pkg.name + '.view' })
