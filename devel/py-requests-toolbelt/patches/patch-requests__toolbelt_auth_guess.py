$NetBSD: patch-requests__toolbelt_auth_guess.py,v 1.1 2015/11/24 10:27:26 wiz Exp $

Fix authentication handlers using digest auth

Requests 2.8.0 introduced a thread-safe HTTPDigestAuth class which was
backwards incompatible for anything that attempts to work with it. This
adds a compatibility layer for convenience based on the version of
requests that is installed alongside the toolbelt.

This also updates the HTTPProxyDigestAuth class to be threadsafe by
utilizing the thread local storage when it is available.

Closes #108
https://github.com/sigmavirus24/requests-toolbelt/commit/d4eba75097c0f65448afb6dfab2029d3fefb02b9

--- requests_toolbelt/auth/guess.py.orig	2015-03-29 04:12:14.000000000 +0000
+++ requests_toolbelt/auth/guess.py
@@ -3,6 +3,8 @@
 from requests import auth
 from requests import cookies
 
+from . import _digest_auth_compat as auth_compat
+
 
 class GuessAuth(auth.AuthBase):
     """Guesses the auth type by the WWW-Authentication header."""
@@ -12,38 +14,57 @@ class GuessAuth(auth.AuthBase):
         self.auth = None
         self.pos = None
 
+    def _handle_basic_auth_401(self, r, kwargs):
+        if self.pos is not None:
+            r.request.body.seek(self.pos)
+
+        # Consume content and release the original connection
+        # to allow our new request to reuse the same one.
+        r.content
+        r.raw.release_conn()
+        prep = r.request.copy()
+        if not hasattr(prep, '_cookies'):
+            prep._cookies = cookies.RequestsCookieJar()
+        cookies.extract_cookies_to_jar(prep._cookies, r.request, r.raw)
+        prep.prepare_cookies(prep._cookies)
+
+        self.auth = auth.HTTPBasicAuth(self.username, self.password)
+        prep = self.auth(prep)
+        _r = r.connection.send(prep, **kwargs)
+        _r.history.append(r)
+        _r.request = prep
+
+        return _r
+
+    def _handle_digest_auth_401(self, r, kwargs):
+        self.auth = auth_compat.HTTPDigestAuth(self.username, self.password)
+        try:
+            self.auth.init_per_thread_state()
+        except AttributeError:
+            # If we're not on requests 2.8.0+ this method does not exist and
+            # is not relevant.
+            pass
+
+        # Check that the attr exists because much older versions of requests
+        # set this attribute lazily. For example:
+        # https://github.com/kennethreitz/requests/blob/33735480f77891754304e7f13e3cdf83aaaa76aa/requests/auth.py#L59
+        if (hasattr(self.auth, 'num_401_calls')
+                and self.auth.num_401_calls is None):
+            self.auth.num_401_calls = 1
+        # Digest auth would resend the request by itself. We can take a
+        # shortcut here.
+        return self.auth.handle_401(r, **kwargs)
+
     def handle_401(self, r, **kwargs):
         """Resends a request with auth headers, if needed."""
 
         www_authenticate = r.headers.get('www-authenticate', '').lower()
 
         if 'basic' in www_authenticate:
-            if self.pos is not None:
-                r.request.body.seek(self.pos)
-
-            # Consume content and release the original connection
-            # to allow our new request to reuse the same one.
-            r.content
-            r.raw.release_conn()
-            prep = r.request.copy()
-            if not hasattr(prep, '_cookies'):
-                prep._cookies = cookies.RequestsCookieJar()
-            cookies.extract_cookies_to_jar(prep._cookies, r.request, r.raw)
-            prep.prepare_cookies(prep._cookies)
-
-            self.auth = auth.HTTPBasicAuth(self.username, self.password)
-            prep = self.auth(prep)
-            _r = r.connection.send(prep, **kwargs)
-            _r.history.append(r)
-            _r.request = prep
-
-            return _r
+            return self._handle_basic_auth_401(r, kwargs)
 
         if 'digest' in www_authenticate:
-            self.auth = auth.HTTPDigestAuth(self.username, self.password)
-            # Digest auth would resend the request by itself. We can take a
-            # shortcut here.
-            return self.auth.handle_401(r, **kwargs)
+            return self._handle_digest_auth_401(r, kwargs)
 
     def __call__(self, request):
         if self.auth is not None:
