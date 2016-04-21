$NetBSD: patch-setup.py,v 1.4 2016/04/21 08:20:45 leot Exp $

Avoid too strict version requirements.

--- setup.py.orig	2016-04-10 00:43:47.000000000 +0000
+++ setup.py
@@ -59,64 +59,64 @@ setup(
     # https://packaging.python.org/en/latest/requirements/#install-requires
     # It is not considered best practice to use install_requires to pin dependencies to specific versions.
     install_requires=[
-        "backports.ssl_match_hostname>=3.5.0.1, <3.6",
-        "blinker>=1.4, <1.5",
-        "click>=6.2, <7.0",
+        "backports.ssl_match_hostname>=3.5.0.1",
+        "blinker>=1.4",
+        "click>=6.2",
         "certifi>=2015.11.20.1",  # no semver here - this should always be on the last release!
-        "configargparse>=0.10, <0.11",
-        "construct>=2.5.2, <2.6",
-        "cryptography>=1.3,<1.4",
-        "Flask>=0.10.1, <0.11",
-        "h2>=2.1.2, <3.0",
-        "hpack>=2.1.0, <3.0",
-        "html2text>=2016.1.8, <=2016.4.2",
-        "hyperframe>=3.2.0, <4.0",
-        "lxml>=3.5.0, <3.7",
-        "Pillow>=3.2, <3.3",
-        "passlib>=1.6.5, <1.7",
-        "pyasn1>=0.1.9, <0.2",
-        "pyOpenSSL>=16.0, <17.0",
-        "pyparsing>=2.1,<2.2",
-        "pyperclip>=1.5.22, <1.6",
-        "requests>=2.9.1, <2.10",
-        "six>=1.10, <1.11",
-        "tornado>=4.3, <4.4",
-        "urwid>=1.3.1, <1.4",
-        "watchdog>=0.8.3, <0.9",
+        "configargparse>=0.10",
+        "construct>=2.5.2",
+        "cryptography>=1.3",
+        "Flask>=0.10.1",
+        "h2>=2.1.2",
+        "hpack>=2.1.0",
+        "html2text>=2016.1.8",
+        "hyperframe>=3.2.0",
+        "lxml>=3.5.0",
+        "Pillow>=3.2",
+        "passlib>=1.6.5",
+        "pyasn1>=0.1.9",
+        "pyOpenSSL>=16.0",
+        "pyparsing>=2.1",
+        "pyperclip>=1.5.22",
+        "requests>=2.9.1",
+        "six>=1.10",
+        "tornado>=4.3",
+        "urwid>=1.3.1",
+        "watchdog>=0.8.3",
     ],
     extras_require={
         ':sys_platform == "win32"': [
-            "pydivert>=0.0.7, <0.1",
+            "pydivert>=0.0.7",
         ],
         ':sys_platform != "win32"': [
         ],
         # Do not use a range operator here: https://bitbucket.org/pypa/setuptools/issues/380
         # Ubuntu Trusty and other still ship with setuptools < 17.1
         ':python_version == "2.7"': [
-            "enum34>=1.0.4, <2",
-            "ipaddress>=1.0.15, <1.1",
+            "enum34>=1.0.4",
+            "ipaddress>=1.0.15",
         ],
         'dev': [
-            "coveralls>=1.1, <1.2",
-            "mock>=1.3.0, <1.4",
-            "pytest>=2.8.7,<2.10",
-            "pytest-cov>=2.2.1, <2.3",
-            "pytest-timeout>=1.0.0, <1.1",
-            "pytest-xdist>=1.14, <1.15",
-            "sphinx>=1.3.5, <1.5",
-            "sphinx-autobuild>=0.5.2, <0.7",
-            "sphinxcontrib-documentedlist>=0.3.0, <0.4",
-            "sphinx_rtd_theme>=0.1.9, <0.2",
+            "coveralls>=1.1",
+            "mock>=1.3.0",
+            "pytest>=2.8.7",
+            "pytest-cov>=2.2.1",
+            "pytest-timeout>=1.0.0",
+            "pytest-xdist>=1.14",
+            "sphinx>=1.3.5",
+            "sphinx-autobuild>=0.5.2",
+            "sphinxcontrib-documentedlist>=0.3.0",
+            "sphinx_rtd_theme>=0.1.9",
         ],
         'contentviews': [
-            "cssutils>=1.0.1, <1.1",
-            "protobuf>=2.6.1, <2.7",
-            "pyamf>=0.8.0, <0.9",
+            "cssutils>=1.0.1",
+            "protobuf>=2.6.1",
+            "pyamf>=0.8.0",
         ],
         'examples': [
-            "beautifulsoup4>=4.4.1, <4.5",
-            "harparser>=0.2, <0.3",
-            "pytz>=2015.07.0, <=2016.3",
+            "beautifulsoup4>=4.4.1",
+            "harparser>=0.2",
+            "pytz>=2015.07.0",
         ]
     }
 )
