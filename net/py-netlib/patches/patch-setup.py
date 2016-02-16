$NetBSD: patch-setup.py,v 1.2 2016/02/16 13:52:41 leot Exp $

Avoid too strict version requirements.

--- setup.py.orig	2016-02-14 15:09:39.000000000 +0000
+++ setup.py
@@ -44,29 +44,29 @@ setup(
     include_package_data=True,
     zip_safe=False,
     install_requires=[
-        "pyasn1>=0.1.9, <0.2",
-        "pyOpenSSL>=0.15.1, <0.16",
-        "cryptography>=1.2.2, <1.3",
-        "passlib>=1.6.5, <1.7",
-        "hpack>=2.1.0, <3.0",
-        "hyperframe>=3.2.0, <4.0",
-        "six>=1.10.0, <1.11",
+        "pyasn1>=0.1.9",
+        "pyOpenSSL>=0.15.1",
+        "cryptography>=1.2.2",
+        "passlib>=1.6.5",
+        "hpack>=2.1.0",
+        "hyperframe>=3.2.0",
+        "six>=1.10.0",
         "certifi>=2015.11.20.1",  # no semver here - this should always be on the last release!
-        "backports.ssl_match_hostname>=3.5.0.1, <3.6",
+        "backports.ssl_match_hostname>=3.5.0.1",
     ],
     extras_require={
         # Do not use a range operator here: https://bitbucket.org/pypa/setuptools/issues/380
         # Ubuntu Trusty and other still ship with setuptools < 17.1
         ':python_version == "2.7"': [
-            "ipaddress>=1.0.15, <1.1",
+            "ipaddress>=1.0.15",
         ],
         'dev': [
-            "mock>=1.3.0, <1.4",
-            "pytest>=2.8.7, <2.9",
-            "pytest-xdist>=1.14, <1.15",
-            "pytest-cov>=2.2.1, <2.3",
-            "pytest-timeout>=1.0.0, <1.1",
-            "coveralls>=1.1, <1.2"
+            "mock>=1.3.0",
+            "pytest>=2.8.7",
+            "pytest-xdist>=1.14",
+            "pytest-cov>=2.2.1",
+            "pytest-timeout>=1.0.0",
+            "coveralls>=1.1"
         ]
     },
 )
