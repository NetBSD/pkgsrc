$NetBSD: patch-Lib_httplib.py,v 1.4 2021/10/10 03:00:59 gutteridge Exp $

bpo-39603 (CVE-2020-26116): header injection via HTTP method

Taken from:
https://gitweb.gentoo.org/fork/cpython.git/commit/?h=gentoo-2.7-vanilla&id=138e2caeb4827ccfd1eaff2cf63afb79dfeeb3c4

Fix CVE-2021-3737: http client infinite line reading (DoS) after a HTTP 100 Continue
Via Fedora:
https://src.fedoraproject.org/rpms/python2.7/blob/rawhide/f/00368-CVE-2021-3737.patch

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
@@ -361,6 +365,25 @@ class HTTPMessage(mimetools.Message):
                 # It's not a header line; skip it and try the next line.
                 self.status = 'Non-header line where header expected'
 
+
+def _read_headers(fp):
+    """Reads potential header lines into a list from a file pointer.
+    Length of line is limited by _MAXLINE, and number of
+    headers is limited by _MAXHEADERS.
+    """
+    headers = []
+    while True:
+        line = fp.readline(_MAXLINE + 1)
+        if len(line) > _MAXLINE:
+            raise LineTooLong("header line")
+        headers.append(line)
+        if len(headers) > _MAXHEADERS:
+            raise HTTPException("got more than %d headers" % _MAXHEADERS)
+        if line in (b'\r\n', b'\n', b''):
+            break
+    return headers
+
+
 class HTTPResponse:
 
     # strict: If true, raise BadStatusLine if the status line can't be
@@ -449,15 +472,10 @@ class HTTPResponse:
             if status != CONTINUE:
                 break
             # skip the header from the 100 response
-            while True:
-                skip = self.fp.readline(_MAXLINE + 1)
-                if len(skip) > _MAXLINE:
-                    raise LineTooLong("header line")
-                skip = skip.strip()
-                if not skip:
-                    break
-                if self.debuglevel > 0:
-                    print "header:", skip
+            skipped_headers = _read_headers(self.fp)
+            if self.debuglevel > 0:
+                print("headers:", skipped_headers)
+            del skipped_headers
 
         self.status = status
         self.reason = reason.strip()
@@ -935,6 +953,8 @@ class HTTPConnection:
         else:
             raise CannotSendRequest()
 
+        self._validate_method(method)
+
         # Save the method for use later in the response phase
         self._method = method
 
@@ -1020,6 +1040,17 @@ class HTTPConnection:
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
