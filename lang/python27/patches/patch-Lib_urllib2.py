$NetBSD: patch-Lib_urllib2.py,v 1.3 2021/10/10 03:00:59 gutteridge Exp $

bpo-39503 (CVE-2020-8492): ReDoS on AbstractBasicAuthHandler

Taken from:
https://gitweb.gentoo.org/fork/cpython.git/commit/?h=gentoo-2.7-vanilla&id=2273e65e11dd0234f2f51ebaef61fc6e848d4059

bpo-43075 (CVE-2021-3733): Fix ReDoS in request

Taken from:
https://github.com/python/cpython/pull/24391/

--- Lib/urllib2.py.orig	2020-04-19 21:13:39.000000000 +0000
+++ Lib/urllib2.py
@@ -856,8 +856,15 @@ class AbstractBasicAuthHandler:
 
     # allow for double- and single-quoted realm values
     # (single quotes are a violation of the RFC, but appear in the wild)
-    rx = re.compile('(?:.*,)*[ \t]*([^ \t]+)[ \t]+'
-                    'realm=(["\']?)([^"\']*)\\2', re.I)
+    rx = re.compile('(?:^|,)'   # start of the string or ','
+                    '[ \t]*'    # optional whitespaces
+                    '([^ \t,]+)' # scheme like "Basic"
+                    '[ \t]+'    # mandatory whitespaces
+                    # realm=xxx
+                    # realm='xxx'
+                    # realm="xxx"
+                    'realm=(["\']?)([^"\']*)\\2',
+                    re.I)
 
     # XXX could pre-emptively send auth info already accepted (RFC 2617,
     # end of section 2, and section 1.2 immediately after "credentials"
@@ -869,23 +876,52 @@ class AbstractBasicAuthHandler:
         self.passwd = password_mgr
         self.add_password = self.passwd.add_password
 
+    def _parse_realm(self, header):
+        # parse WWW-Authenticate header: accept multiple challenges per header
+        found_challenge = False
+        for mo in AbstractBasicAuthHandler.rx.finditer(header):
+            scheme, quote, realm = mo.groups()
+            if quote not in ['"', "'"]:
+                warnings.warn("Basic Auth Realm was unquoted",
+                              UserWarning, 3)
+
+            yield (scheme, realm)
+
+            found_challenge = True
+
+        if not found_challenge:
+            if header:
+                scheme = header.split()[0]
+            else:
+                scheme = ''
+            yield (scheme, None)
 
     def http_error_auth_reqed(self, authreq, host, req, headers):
         # host may be an authority (without userinfo) or a URL with an
         # authority
-        # XXX could be multiple headers
-        authreq = headers.get(authreq, None)
-
-        if authreq:
-            mo = AbstractBasicAuthHandler.rx.search(authreq)
-            if mo:
-                scheme, quote, realm = mo.groups()
-                if quote not in ['"', "'"]:
-                    warnings.warn("Basic Auth Realm was unquoted",
-                                  UserWarning, 2)
-                if scheme.lower() == 'basic':
+        headers = headers.getheaders(authreq)
+        if not headers:
+            # no header found
+            return
+
+        unsupported = None
+        for header in headers:
+            for scheme, realm in self._parse_realm(header):
+                if scheme.lower() != 'basic':
+                    unsupported = scheme
+                    continue
+
+                if realm is not None:
+                    # Use the first matching Basic challenge.
+                    # Ignore following challenges even if they use the Basic
+                    # scheme.
                     return self.retry_http_basic_auth(host, req, realm)
 
+        if unsupported is not None:
+            raise ValueError("AbstractBasicAuthHandler does not "
+                             "support the following scheme: %r"
+                             % (scheme,))
+
     def retry_http_basic_auth(self, host, req, realm):
         user, pw = self.passwd.find_user_password(realm, host)
         if pw is not None:
