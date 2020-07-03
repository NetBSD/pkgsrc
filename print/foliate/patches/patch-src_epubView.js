$NetBSD: patch-src_epubView.js,v 1.3 2020/07/03 12:18:12 fox Exp $

Adds variable to help substitute the correct python version suffix.

--- src/epubView.js.orig	2020-07-02 07:05:56.000000000 +0000
+++ src/epubView.js
@@ -25,7 +25,7 @@ const {
     mimetypes, mimetypeIs, execCommand, recursivelyDeleteDir
 } = imports.utils
 
-const python = GLib.find_program_in_path('python') || GLib.find_program_in_path('python3')
+const python = GLib.find_program_in_path('python@PYVERSSUFFIX@')
 const kindleUnpack = pkg.pkgdatadir + '/assets/KindleUnpack/kindleunpack.py'
 
 const settings = new Gio.Settings({ schema_id: pkg.name + '.view' })
