$NetBSD: patch-src___cffi__src_openssl_callbacks.py,v 1.1 2017/01/28 11:15:07 wiz Exp $

Use static callbacks with Python 3.x again #3350
https://github.com/pyca/cryptography/pull/3350

--- src/_cffi_src/openssl/callbacks.py.orig	2017-01-27 15:10:32.000000000 +0000
+++ src/_cffi_src/openssl/callbacks.py
@@ -4,8 +4,6 @@
 
 from __future__ import absolute_import, division, print_function
 
-import sys
-
 import cffi
 
 INCLUDES = """
@@ -50,7 +48,7 @@ CUSTOMIZATIONS = """
 static const long Cryptography_STATIC_CALLBACKS = 1;
 """
 
-if cffi.__version_info__ < (1, 4, 0) or sys.version_info >= (3, 5):
+if cffi.__version_info__ < (1, 4, 0):
     # backwards compatibility for old cffi version on PyPy
     # and Python >=3.5 (https://github.com/pyca/cryptography/issues/2970)
     TYPES = "static const long Cryptography_STATIC_CALLBACKS;"
