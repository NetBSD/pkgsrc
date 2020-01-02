$NetBSD: patch-setup.py,v 1.3 2020/01/02 19:22:41 bsiegert Exp $

Relax requirements.

--- setup.py.orig	2019-10-16 20:08:15.000000000 +0000
+++ setup.py
@@ -44,15 +44,15 @@ requires = [
     'httplib2>=0.11.3',
     'google-reauth>=0.1.0',
     # TODO: Sync submodule with tag referenced here once #339 is fixed in mock.
-    'mock==2.0.0',
+    'mock>=2.0.0',
     'monotonic>=1.4',
-    'oauth2client==4.1.3',
+    'oauth2client>=4.1.3',
     'pyOpenSSL>=0.13',
     'retry_decorator>=1.0.0',
     'six>=1.12.0',
     # Not using 1.02 because of:
     #   https://code.google.com/p/socksipy-branch/issues/detail?id=3
-    'SocksiPy-branch==1.01',
+    'SocksiPy-branch>=1.01',
 ]
 
 CURDIR = os.path.abspath(os.path.dirname(__file__))
