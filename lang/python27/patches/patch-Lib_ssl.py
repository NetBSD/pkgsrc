$NetBSD: patch-Lib_ssl.py,v 1.1 2015/04/24 03:01:36 rodent Exp $

Fix build with LibreSSL.

--- Lib/ssl.py.orig	2014-12-10 15:59:40.000000000 +0000
+++ Lib/ssl.py
@@ -106,7 +106,12 @@ from _ssl import CERT_NONE, CERT_OPTIONA
 from _ssl import (VERIFY_DEFAULT, VERIFY_CRL_CHECK_LEAF, VERIFY_CRL_CHECK_CHAIN,
     VERIFY_X509_STRICT)
 from _ssl import txt2obj as _txt2obj, nid2obj as _nid2obj
-from _ssl import RAND_status, RAND_egd, RAND_add
+from _ssl import RAND_status, RAND_add
+try:
+    from _ssl import RAND_egd
+except ImportError:
+    # LibreSSL does not provide RAND_egd
+    pass
 
 def _import_symbols(prefix):
     for n in dir(_ssl):
