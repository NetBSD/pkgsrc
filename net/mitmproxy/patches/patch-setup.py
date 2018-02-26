$NetBSD: patch-setup.py,v 1.6 2018/02/26 12:28:48 leot Exp $

Avoid too strict version requirements.

--- setup.py.orig	2018-02-22 12:17:33.000000000 +0000
+++ setup.py
@@ -61,47 +61,47 @@ setup(
     # https://packaging.python.org/en/latest/requirements/#install-requires
     # It is not considered best practice to use install_requires to pin dependencies to specific versions.
     install_requires=[
-        "blinker>=1.4, <1.5",
-        "brotlipy>=0.7.0,<0.8",
+        "blinker>=1.4",
+        "brotlipy>=0.7.0",
         "certifi>=2015.11.20.1",  # no semver here - this should always be on the last release!
-        "click>=6.2, <7",
-        "cryptography>=2.1.4,<2.2",
-        'h11>=0.7.0,<0.8',
-        "h2>=3.0.1,<4",
-        "hyperframe>=5.1.0,<6",
-        "kaitaistruct>=0.7,<0.9",
-        "ldap3>=2.4,<2.5",
-        "passlib>=1.6.5, <1.8",
-        "pyasn1>=0.3.1,<0.5",
-        "pyOpenSSL>=17.5,<17.6",
-        "pyparsing>=2.1.3, <2.3",
-        "pyperclip>=1.6.0, <1.7",
-        "requests>=2.9.1, <3",
-        "ruamel.yaml>=0.13.2, <0.16",
-        "sortedcontainers>=1.5.4, <1.6",
-        "tornado>=4.3, <4.6",
-        "urwid>=2.0.1,<2.1",
-        "wsproto>=0.11.0,<0.12.0",
+        "click>=6.2",
+        "cryptography>=2.1.4",
+        'h11>=0.7.0',
+        "h2>=3.0.1",
+        "hyperframe>=5.1.0",
+        "kaitaistruct>=0.7",
+        "ldap3>=2.4",
+        "passlib>=1.6.5",
+        "pyasn1>=0.3.1",
+        "pyOpenSSL>=17.5",
+        "pyparsing>=2.1.3",
+        "pyperclip>=1.6.0",
+        "requests>=2.9.1",
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
-            "flake8>=3.5, <3.6",
-            "Flask>=0.10.1, <0.13",
-            "mypy>=0.560,<0.561",
-            "pytest-cov>=2.5.1,<3",
-            "pytest-faulthandler>=1.3.1,<2",
-            "pytest-timeout>=1.2.1,<2",
-            "pytest-xdist>=1.22,<2",
-            "pytest>=3.3,<4",
-            "tox>=2.3, <3",
-            "rstcheck>=2.2, <4.0",
+            "flake8>=3.5",
+            "Flask>=0.10.1",
+            "mypy>=0.560",
+            "pytest-cov>=2.5.1",
+            "pytest-faulthandler>=1.3.1",
+            "pytest-timeout>=1.2.1",
+            "pytest-xdist>=1.22",
+            "pytest>=3.3",
+            "tox>=2.3",
+            "rstcheck>=2.2",
         ],
         'examples': [
-            "beautifulsoup4>=4.4.1, <4.7",
-            "Pillow>=4.3,<5.1",
+            "beautifulsoup4>=4.4.1",
+            "Pillow>=4.3",
         ]
     }
 )
