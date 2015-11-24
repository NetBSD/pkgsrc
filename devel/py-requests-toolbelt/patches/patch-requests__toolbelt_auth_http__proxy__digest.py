$NetBSD: patch-requests__toolbelt_auth_http__proxy__digest.py,v 1.1 2015/11/24 10:27:26 wiz Exp $

Fix authentication handlers using digest auth

Requests 2.8.0 introduced a thread-safe HTTPDigestAuth class which was
backwards incompatible for anything that attempts to work with it. This
adds a compatibility layer for convenience based on the version of
requests that is installed alongside the toolbelt.

This also updates the HTTPProxyDigestAuth class to be threadsafe by
utilizing the thread local storage when it is available.

Closes #108
https://github.com/sigmavirus24/requests-toolbelt/commit/d4eba75097c0f65448afb6dfab2029d3fefb02b9

--- requests_toolbelt/auth/http_proxy_digest.py.orig	2015-03-29 04:12:14.000000000 +0000
+++ requests_toolbelt/auth/http_proxy_digest.py
@@ -2,9 +2,10 @@
 """The module containing HTTPProxyDigestAuth."""
 import re
 
-from requests import auth
 from requests import cookies
 
+from . import _digest_auth_compat as auth
+
 
 class HTTPProxyDigestAuth(auth.HTTPDigestAuth):
     """HTTP digest authentication between proxy
@@ -21,6 +22,30 @@ class HTTPProxyDigestAuth(auth.HTTPDiges
         super(HTTPProxyDigestAuth, self).__init__(*args, **kwargs)
         self.stale_rejects = 0
 
+        self.init_per_thread_state()
+
+    @property
+    def stale_rejects(self):
+        thread_local = getattr(self, '_thread_local', None)
+        if thread_local is None:
+            return self._stale_rejects
+        return thread_local.stale_rejects
+
+    @stale_rejects.setter
+    def stale_rejects(self, value):
+        thread_local = getattr(self, '_thread_local', None)
+        if thread_local is None:
+            self._stale_rejects = value
+        else:
+            thread_local.stale_rejects = value
+
+    def init_per_thread_state(self):
+        try:
+            super(HTTPProxyDigestAuth, self).init_per_thread_state()
+        except AttributeError:
+            # If we're not on requests 2.8.0+ this method does not exist
+            pass
+
     def handle_407(self, r, **kwargs):
         """Handle HTTP 407 only once, otherwise give up
 
@@ -64,6 +89,7 @@ class HTTPProxyDigestAuth(auth.HTTPDiges
             return r
 
     def __call__(self, r):
+        self.init_per_thread_state()
         # if we have nonce, then just use it, otherwise server will tell us
         if self.last_nonce:
             r.headers['Proxy-Authorization'] = self.build_digest_header(
