$NetBSD: patch-src_epubView.js,v 1.1 2020/04/06 14:15:47 fox Exp $

Adds variable to help substitute the correct python version suffix.

--- src/epubView.js.orig	2020-04-06 13:02:45.032535873 +0000
+++ src/epubView.js
@@ -21,7 +21,7 @@ const {
     mimetypes, execCommand, recursivelyDeleteDir
 } = imports.utils
 
-const python = GLib.find_program_in_path('python') || GLib.find_program_in_path('python3')
+const python = GLib.find_program_in_path('python@PYVERSSUFFIX@')
 const kindleUnpack = pkg.pkgdatadir + '/assets/KindleUnpack/kindleunpack.py'
 
 const settings = new Gio.Settings({ schema_id: pkg.name + '.view' })
