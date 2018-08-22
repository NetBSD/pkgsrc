$NetBSD: patch-setup.py,v 1.1 2018/08/22 08:31:30 adam Exp $

Relax requirements.

--- setup.py.orig	2018-08-22 06:24:42.000000000 +0000
+++ setup.py
@@ -36,7 +36,7 @@ management tasks, including:
 
 requires = [
     'argcomplete>=1.9.4',
-    'boto==2.48.0',
+    'boto>=2.48.0',
     'crcmod>=1.7',
     'fasteners>=0.14.1',
     'gcs-oauth2-boto-plugin>=2.1',
@@ -44,16 +44,16 @@ requires = [
     'httplib2>=0.11.3',
     'google-reauth>=0.1.0',
     # TODO: Sync submodule with tag referenced here once #339 is fixed in mock.
-    'mock==2.0.0',
+    'mock>=2.0.0',
     'monotonic>=1.4',
-    'oauth2client==4.1.2',
+    'oauth2client>=4.1.2',
     'pyOpenSSL>=0.13',
     'python-gflags>=2.0',
     'retry_decorator>=1.0.0',
     'six>=1.9.0',
     # Not using 1.02 because of:
     #   https://code.google.com/p/socksipy-branch/issues/detail?id=3
-    'SocksiPy-branch==1.01',
+    'SocksiPy-branch>=1.01',
 ]
 
 dependency_links = [
