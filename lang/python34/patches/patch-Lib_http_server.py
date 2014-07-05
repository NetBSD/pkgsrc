$NetBSD: patch-Lib_http_server.py,v 1.1.2.2 2014/07/05 11:30:58 tron Exp $

Apply fix for directory traversal vulnerability, ref.
http://bugs.python.org/issue21766

--- Lib/http/server.py.orig	2014-05-19 05:19:38.000000000 +0000
+++ Lib/http/server.py
@@ -977,7 +977,7 @@ class CGIHTTPRequestHandler(SimpleHTTPRe
         (and the next character is a '/' or the end of the string).
 
         """
-        collapsed_path = _url_collapse_path(self.path)
+        collapsed_path = _url_collapse_path(urllib.parse.unquote(self.path))
         dir_sep = collapsed_path.find('/', 1)
         head, tail = collapsed_path[:dir_sep], collapsed_path[dir_sep+1:]
         if head in self.cgi_directories:
