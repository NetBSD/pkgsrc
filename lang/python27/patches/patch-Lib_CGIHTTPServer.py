$NetBSD: patch-Lib_CGIHTTPServer.py,v 1.1 2014/07/02 08:22:02 he Exp $

Fix for directory-traversal vulnerability, ref.
http://bugs.python.org/issue21766

--- Lib/CGIHTTPServer.py.orig	2014-06-09 11:29:36.000000000 +0000
+++ Lib/CGIHTTPServer.py
@@ -84,7 +84,7 @@ class CGIHTTPRequestHandler(SimpleHTTPSe
         path begins with one of the strings in self.cgi_directories
         (and the next character is a '/' or the end of the string).
         """
-        collapsed_path = _url_collapse_path(self.path)
+        collapsed_path = _url_collapse_path(urllib.unquote(self.path))
         dir_sep = collapsed_path.find('/', 1)
         head, tail = collapsed_path[:dir_sep], collapsed_path[dir_sep+1:]
         if head in self.cgi_directories:
