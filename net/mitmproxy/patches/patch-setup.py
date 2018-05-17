$NetBSD: patch-setup.py,v 1.8 2018/05/17 13:06:13 leot Exp $

Avoid too strict version requirements.

--- setup.py.orig	2018-05-17 07:39:27.000000000 +0000
+++ setup.py
@@ -60,47 +60,47 @@ setup(
     # https://packaging.python.org/en/latest/requirements/#install-requires
     # It is not considered best practice to use install_requires to pin dependencies to specific versions.
     install_requires=[
-        "blinker>=1.4, <1.5",
-        "brotlipy>=0.7.0,<0.8",
+        "blinker>=1.4",
+        "brotlipy>=0.7.0",
         "certifi>=2015.11.20.1",  # no semver here - this should always be on the last release!
-        "click>=6.2, <7",
-        "cryptography>=2.1.4,<2.3",
-        "h2>=3.0.1,<4",
-        "hyperframe>=5.1.0,<6",
-        "kaitaistruct>=0.7,<0.9",
-        "ldap3>=2.5,<2.6",
-        "passlib>=1.6.5, <1.8",
-        "pyasn1>=0.3.1,<0.5",
-        "pyOpenSSL>=17.5,<17.6",
-        "pyparsing>=2.1.3, <2.3",
-        "pyperclip>=1.6.0, <1.7",
-        "ruamel.yaml>=0.13.2, <0.16",
-        "sortedcontainers>=1.5.4, <1.6",
-        "tornado>=4.3,<5.1",
-        "urwid>=2.0.1,<2.1",
-        "wsproto>=0.11.0,<0.12.0",
+        "click>=6.2",
+        "cryptography>=2.1.4",
+        "h2>=3.0.1",
+        "hyperframe>=5.1.0",
+        "kaitaistruct>=0.7",
+        "ldap3>=2.5",
+        "passlib>=1.6.5",
+        "pyasn1>=0.3.1",
+        "pyOpenSSL>=17.5",
+        "pyparsing>=2.1.3",
+        "pyperclip>=1.6.0",
+        "ruamel.yaml>=0.13.2",
+        "sortedcontainers>=1.5.4",
+        "tornado>=4.3",
+        "urwid>=2.0.1",
+        "wsproto>=0.11.0",
     ],
     extras_require={
         ':sys_platform == "win32"': [
-            "pydivert>=2.0.3,<2.2",
+            "pydivert>=2.0.3",
         ],
         'dev': [
             "asynctest>=0.12.0",
-            "flake8>=3.5, <3.6",
-            "Flask>=1.0,<1.1",
-            "mypy>=0.590,<0.591",
+            "flake8>=3.5",
+            "Flask>=1.0",
+            "mypy>=0.590",
             "pytest-asyncio>=0.8",
-            "pytest-cov>=2.5.1,<3",
-            "pytest-faulthandler>=1.3.1,<2",
-            "pytest-timeout>=1.2.1,<2",
-            "pytest-xdist>=1.22,<2",
-            "pytest>=3.3,<4",
-            "requests>=2.9.1, <3",
-            "tox>=3.0,<3.1",
-            "rstcheck>=2.2, <4.0",
+            "pytest-cov>=2.5.1",
+            "pytest-faulthandler>=1.3.1",
+            "pytest-timeout>=1.2.1",
+            "pytest-xdist>=1.22",
+            "pytest>=3.3",
+            "requests>=2.9.1",
+            "tox>=3.0",
+            "rstcheck>=2.2",
         ],
         'examples': [
-            "beautifulsoup4>=4.4.1, <4.7"
+            "beautifulsoup4>=4.4.1"
         ]
     }
 )
