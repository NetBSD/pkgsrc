$NetBSD: patch-Lib_ssl.py,v 1.1 2015/04/24 03:24:32 rodent Exp $

Fix build with LibreSSL.

--- Lib/ssl.py.orig	2014-10-12 07:03:53.000000000 +0000
+++ Lib/ssl.py
@@ -78,7 +78,12 @@ try:
     from _ssl import OP_SINGLE_ECDH_USE
 except ImportError:
     pass
-from _ssl import RAND_status, RAND_egd, RAND_add, RAND_bytes, RAND_pseudo_bytes
+from _ssl import RAND_status, RAND_add, RAND_bytes, RAND_pseudo_bytes
+try:
+    from _ssl import RAND_egd
+except ImportError:
+    # LibreSSL does not provide RAND_egd
+    pass
 from _ssl import (
     SSL_ERROR_ZERO_RETURN,
     SSL_ERROR_WANT_READ,
