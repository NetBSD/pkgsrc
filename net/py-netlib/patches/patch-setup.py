$NetBSD: patch-setup.py,v 1.1 2016/01/21 00:15:50 leot Exp $

Avoid too strict version requirements.

--- setup.py.orig	2015-12-25 14:55:52.000000000 +0000
+++ setup.py
@@ -15,17 +15,17 @@ with open(os.path.join(here, 'README.rst
     long_description = f.read()
 
 deps = {
-    "pyasn1>=0.1.9, <0.2",
-    "pyOpenSSL>=0.15.1, <0.16",
-    "cryptography>=1.1.1, <1.2",
-    "passlib>=1.6.5, <1.7",
-    "hpack>=2.0.1, <2.1",
-    "six>=1.10.0, <1.11",
+    "pyasn1>=0.1.9",
+    "pyOpenSSL>=0.15.1",
+    "cryptography>=1.1.1",
+    "passlib>=1.6.5",
+    "hpack>=2.0.1",
+    "six>=1.10.0",
     "certifi>=2015.9.6.2",  # no semver here - this should always be on the last release!
-    "backports.ssl_match_hostname>=3.5.0.1, <3.6",
+    "backports.ssl_match_hostname>=3.5.0.1",
 }
 if sys.version_info < (3, 0):
-    deps.add("ipaddress>=1.0.15, <1.1")
+    deps.add("ipaddress>=1.0.15")
 
 setup(
     name="netlib",
