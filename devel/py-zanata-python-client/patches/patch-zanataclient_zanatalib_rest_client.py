$NetBSD: patch-zanataclient_zanatalib_rest_client.py,v 1.1 2016/03/05 04:47:44 ryoon Exp $

--- zanataclient/zanatalib/rest/client.py.orig	2016-01-20 23:38:42.000000000 +0000
+++ zanataclient/zanatalib/rest/client.py
@@ -29,7 +29,7 @@ except ImportError:
     from urlparse import urlparse
 import sys
 import warnings
-from io import StringIO
+import StringIO
 warnings.simplefilter("ignore", DeprecationWarning)
 import httplib2
 
@@ -54,7 +54,7 @@ class RestClient(object):
         if body is not None:
             thelen = str(len(body))
             headers['Content-Length'] = thelen
-            body = StringIO(body)
+            body = StringIO.StringIO(body)
 
         try:
             response, content = self.http_client.request(resource, method.upper(), body, headers=headers)
