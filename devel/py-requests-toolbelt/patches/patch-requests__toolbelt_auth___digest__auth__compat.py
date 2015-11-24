$NetBSD: patch-requests__toolbelt_auth___digest__auth__compat.py,v 1.1 2015/11/24 10:27:26 wiz Exp $

Fix authentication handlers using digest auth

Requests 2.8.0 introduced a thread-safe HTTPDigestAuth class which was
backwards incompatible for anything that attempts to work with it. This
adds a compatibility layer for convenience based on the version of
requests that is installed alongside the toolbelt.

This also updates the HTTPProxyDigestAuth class to be threadsafe by
utilizing the thread local storage when it is available.

Closes #108
https://github.com/sigmavirus24/requests-toolbelt/commit/d4eba75097c0f65448afb6dfab2029d3fefb02b9

--- requests_toolbelt/auth/_digest_auth_compat.py.orig	2015-11-24 10:22:14.000000000 +0000
+++ requests_toolbelt/auth/_digest_auth_compat.py
@@ -0,0 +1,29 @@
+"""Provide a compatibility layer for requests.auth.HTTPDigestAuth."""
+import requests
+
+
+class _ThreadingDescriptor(object):
+    def __init__(self, prop, default):
+        self.prop = prop
+        self.default = default
+
+    def __get__(self, obj, objtype=None):
+        return getattr(obj._thread_local, self.prop, self.default)
+
+    def __set__(self, obj, value):
+        setattr(obj._thread_local, self.prop, value)
+
+
+class _HTTPDigestAuth(requests.auth.HTTPDigestAuth):
+    init = _ThreadingDescriptor('init', True)
+    last_nonce = _ThreadingDescriptor('last_nonce', '')
+    nonce_count = _ThreadingDescriptor('nonce_count', 0)
+    chal = _ThreadingDescriptor('chal', {})
+    pos = _ThreadingDescriptor('pos', None)
+    num_401_calls = _ThreadingDescriptor('num_401_calls', 1)
+
+
+if requests.__build__ < 0x020800:
+    HTTPDigestAuth = requests.auth.HTTPDigestAuth
+else:
+    HTTPDigestAuth = _HTTPDigestAuth
