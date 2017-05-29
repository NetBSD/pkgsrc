$NetBSD: patch-requests_____init____.py,v 1.2 2017/05/29 10:43:42 adam Exp $

* Add workaround for segfault of security/py-certbot on NetBSD/amd64
  7.0.2 and 7.99.53. It seems that the real root cause is in
  security/py-OpenSSL or OpenSSL. However I do not find how to fix it.

  This is introduced in https://github.com/shazow/urllib3

commit 770105ebda5a3a495c944baba51a61fdba1814c7
Author: Cory Benfield <lukasaoz@gmail.com>
Date:   Tue Jul 19 13:00:31 2016 +0100

    Clean up some bugs.

via https://github.com/kennethreitz/requests

t 99fa7becf263473c7bfc1998b41c2c6c80a0f499
Author: Cory Benfield <lukasaoz@gmail.com>
Date:   Tue Nov 15 10:09:11 2016 +0000

    Update urllib3 to 1.19

--- requests/__init__.py.orig	2017-05-27 23:15:49.000000000 +0000
+++ requests/__init__.py
@@ -76,7 +76,7 @@ except AssertionError:
 # Attempt to enable urllib3's SNI support, if possible
 try:
     from urllib3.contrib import pyopenssl
-    pyopenssl.inject_into_urllib3()
+    #pyopenssl.inject_into_urllib3()
 except ImportError:
     pass
 
