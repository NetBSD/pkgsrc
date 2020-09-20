$NetBSD: patch-Lib_httplib.py,v 1.1 2020/09/20 11:06:23 mgorny Exp $

--- Lib/httplib.py.orig	2020-04-19 21:13:39.000000000 +0000
+++ Lib/httplib.py
@@ -257,6 +257,10 @@ _contains_disallowed_url_pchar_re = re.c
 #  _is_allowed_url_pchars_re = re.compile(r"^[/!$&'()*+,;=:@%a-zA-Z0-9._~-]+$")
 # We are more lenient for assumed real world compatibility purposes.
 
+# These characters are not allowed within HTTP method names
+# to prevent http header injection.
+_contains_disallowed_method_pchar_re = re.compile('[\x00-\x1f]')
+
 # We always set the Content-Length header for these methods because some
 # servers will otherwise respond with a 411
 _METHODS_EXPECTING_BODY = {'PATCH', 'POST', 'PUT'}
@@ -935,6 +939,8 @@ class HTTPConnection:
         else:
             raise CannotSendRequest()
 
+        self._validate_method(method)
+
         # Save the method for use later in the response phase
         self._method = method
 
@@ -1020,6 +1026,17 @@ class HTTPConnection:
         # On Python 2, request is already encoded (default)
         return request
 
+    def _validate_method(self, method):
+        """Validate a method name for putrequest."""
+        # prevent http header injection
+        match = _contains_disallowed_method_pchar_re.search(method)
+        if match:
+            msg = (
+                "method can't contain control characters. {method!r} "
+                "(found at least {matched!r})"
+            ).format(matched=match.group(), method=method)
+            raise ValueError(msg)
+
     def _validate_path(self, url):
         """Validate a url for putrequest."""
         # Prevent CVE-2019-9740.
