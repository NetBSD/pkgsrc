$NetBSD: patch-synapse_http_proxy.py,v 1.1 2024/11/24 13:57:45 js Exp $

Upstream thinks private Twisted functions are for them to use. And to
absolutely nobody's surprise, this of course broke when Twised was updated.

--- synapse/http/proxy.py.orig	2024-11-24 13:33:04.649198671 +0000
+++ synapse/http/proxy.py
@@ -62,14 +62,11 @@ HOP_BY_HOP_HEADERS = {
     "Upgrade",
 }
 
-if hasattr(Headers, "_canonicalNameCaps"):
-    # Twisted < 24.7.0rc1
-    _canonicalHeaderName = Headers()._canonicalNameCaps  # type: ignore[attr-defined]
-else:
-    # Twisted >= 24.7.0rc1
-    # But note that `_encodeName` still exists on prior versions,
-    # it just encodes differently
-    _canonicalHeaderName = Headers()._encodeName
+
+def _canonicalHeaderName(name):
+    if isinstance(name, unicode):
+        return name.lower().encode('iso-8859-1')
+    return name.lower()
 
 
 def parse_connection_header_value(
