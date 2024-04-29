$NetBSD: patch-bugzilla___session.py,v 1.1 2024/04/29 18:57:35 bsiegert Exp $

Fix for API key leak, https://github.com/python-bugzilla/python-bugzilla/issues/187
--- bugzilla/_session.py.orig	2021-10-05 20:49:16.000000000 +0000
+++ bugzilla/_session.py
@@ -97,14 +97,14 @@ class _BugzillaSession(object):
         if "timeout" not in kwargs:
             kwargs["timeout"] = timeout
 
-        response = self._session.request(*args, **kwargs)
+        try:
+            response = self._session.request(*args, **kwargs)
 
-        if self._is_xmlrpc:
-            # Yes this still appears to matter for properly decoding unicode
-            # code points in bugzilla.redhat.com content
-            response.encoding = "UTF-8"
+            if self._is_xmlrpc:
+                # Yes this still appears to matter for properly decoding unicode
+                # code points in bugzilla.redhat.com content
+                response.encoding = "UTF-8"
 
-        try:
             response.raise_for_status()
         except Exception as e:
             # Scrape the api key out of the returned exception string
