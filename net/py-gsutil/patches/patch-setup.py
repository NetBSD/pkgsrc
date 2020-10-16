$NetBSD: patch-setup.py,v 1.5 2020/10/16 07:41:10 bsiegert Exp $

Relax requirements.

--- setup.py.orig	2020-08-19 21:17:24.000000000 +0000
+++ setup.py
@@ -44,7 +44,7 @@ requires = [
     'httplib2>=0.18',
     'google-reauth>=0.1.0',
     # TODO: Sync submodule with tag referenced here once #339 is fixed in mock.
-    'mock==2.0.0',
+    'mock>=2.0.0',
     'monotonic>=1.4',
     'pyOpenSSL>=0.13',
     'retry_decorator>=1.0.0',
