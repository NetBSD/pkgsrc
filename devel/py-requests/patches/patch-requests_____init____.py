$NetBSD: patch-requests_____init____.py,v 1.4 2018/10/22 07:55:36 adam Exp $

* Allow newer py-urllib3 and py-chardet.
* Add workaround for segfault of security/py-certbot on NetBSD/amd64
  7.0.2 and 7.99.53. It seems that the real root cause is in
  security/py-OpenSSL or OpenSSL. However I do not find how to fix it.

  This is introduced in https://github.com/shazow/urllib3

--- requests/__init__.py.orig	2018-10-18 15:41:45.000000000 +0000
+++ requests/__init__.py
@@ -60,15 +60,12 @@ def check_compatibility(urllib3_version,
     # urllib3 >= 1.21.1, <= 1.24
     assert major == 1
     assert minor >= 21
-    assert minor <= 24
 
     # Check chardet for compatibility.
     major, minor, patch = chardet_version.split('.')[:3]
     major, minor, patch = int(major), int(minor), int(patch)
     # chardet >= 3.0.2, < 3.1.0
     assert major == 3
-    assert minor < 1
-    assert patch >= 2
 
 
 def _check_cryptography(cryptography_version):
@@ -93,7 +90,6 @@ except (AssertionError, ValueError):
 # Attempt to enable urllib3's SNI support, if possible
 try:
     from urllib3.contrib import pyopenssl
-    pyopenssl.inject_into_urllib3()
 
     # Check cryptography version
     from cryptography import __version__ as cryptography_version
