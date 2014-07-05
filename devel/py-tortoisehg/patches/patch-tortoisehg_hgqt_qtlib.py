$NetBSD: patch-tortoisehg_hgqt_qtlib.py,v 1.1 2014/07/05 15:33:03 wiz Exp $

* Point to docs installed on computer instead of online docs.

--- tortoisehg/hgqt/qtlib.py.orig	2014-03-05 15:42:01.000000000 +0000
+++ tortoisehg/hgqt/qtlib.py
@@ -57,7 +57,7 @@ def gettempdir():
 def openhelpcontents(url):
     'Open online help, use local CHM file if available'
     if not url.startswith('http'):
-        fullurl = 'http://tortoisehg.readthedocs.org/en/latest/' + url
+        fullurl = 'file://'+ paths.doc_path + '/html/' + url
         # Use local CHM file if it can be found
         if os.name == 'nt' and paths.bin_path:
             chm = os.path.join(paths.bin_path, 'doc', 'TortoiseHg.chm')
