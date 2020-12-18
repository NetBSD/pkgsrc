$NetBSD: patch-requests_____init____.py,v 1.8 2020/12/18 08:22:39 adam Exp $

* Add workaround for segfault of security/py-certbot on NetBSD/amd64
  7.0.2 and 7.99.53. It seems that the real root cause is in
  security/py-OpenSSL or OpenSSL. However I do not find how to fix it.

  This is introduced in https://github.com/shazow/urllib3

--- requests/__init__.py.orig	2020-12-16 17:43:25.000000000 +0000
+++ requests/__init__.py
@@ -99,7 +99,6 @@ try:
 
     if not getattr(ssl, "HAS_SNI", False):
         from urllib3.contrib import pyopenssl
-        pyopenssl.inject_into_urllib3()
 
         # Check cryptography version
         from cryptography import __version__ as cryptography_version
