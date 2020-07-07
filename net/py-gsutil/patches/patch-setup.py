$NetBSD: patch-setup.py,v 1.4 2020/07/07 16:49:19 bsiegert Exp $

Relax requirements.

--- setup.py.orig	2020-05-19 21:00:16.000000000 +0000
+++ setup.py
@@ -44,14 +44,14 @@ requires = [
     'httplib2>=0.11.3',
     'google-reauth>=0.1.0',
     # TODO: Sync submodule with tag referenced here once #339 is fixed in mock.
-    'mock==2.0.0',
+    'mock>=2.0.0',
     'monotonic>=1.4',
     'pyOpenSSL>=0.13',
     'retry_decorator>=1.0.0',
     'six>=1.12.0',
     # Not using 1.02 because of:
     #   https://code.google.com/p/socksipy-branch/issues/detail?id=3
-    'SocksiPy-branch==1.01',
+    'SocksiPy-branch>=1.01',
 ]
 
 CURDIR = os.path.abspath(os.path.dirname(__file__))
