$NetBSD: patch-setup.py,v 1.5 2017/04/14 13:15:04 leot Exp $

Avoid too strict version requirements.

--- setup.py.orig	2017-03-15 18:44:08.000000000 +0000
+++ setup.py
@@ -60,61 +60,61 @@ setup(
     # https://packaging.python.org/en/latest/requirements/#install-requires
     # It is not considered best practice to use install_requires to pin dependencies to specific versions.
     install_requires=[
-        "blinker>=1.4, <1.5",
-        "click>=6.2, <7",
+        "blinker>=1.4",
+        "click>=6.2",
         "certifi>=2015.11.20.1",  # no semver here - this should always be on the last release!
-        "construct>=2.8, <2.9",
-        "cryptography>=1.3, <1.9",
-        "cssutils>=1.0.1, <1.1",
-        "h2>=2.5.1, <3",
-        "html2text>=2016.1.8, <=2016.9.19",
-        "hyperframe>=4.0.1, <5",
-        "jsbeautifier>=1.6.3, <1.7",
-        "kaitaistruct>=0.6, <0.7",
-        "passlib>=1.6.5, <1.8",
-        "pyasn1>=0.1.9, <0.3",
-        "pyOpenSSL>=16.0, <17.0",
-        "pyparsing>=2.1.3, <2.3",
-        "pyperclip>=1.5.22, <1.6",
-        "requests>=2.9.1, <3",
-        "ruamel.yaml>=0.13.2, <0.14",
-        "tornado>=4.3, <4.5",
-        "urwid>=1.3.1, <1.4",
-        "watchdog>=0.8.3, <0.9",
-        "brotlipy>=0.5.1, <0.7",
-        "sortedcontainers>=1.5.4, <1.6",
+        "construct>=2.8",
+        "cryptography>=1.3",
+        "cssutils>=1.0.1",
+        "h2>=2.5.1",
+        "html2text>=2016.1.8",
+        "hyperframe>=4.0.1",
+        "jsbeautifier>=1.6.3",
+        "kaitaistruct>=0.6",
+        "passlib>=1.6.5",
+        "pyasn1>=0.1.9",
+        "pyOpenSSL>=16.0",
+        "pyparsing>=2.1.3",
+        "pyperclip>=1.5.22",
+        "requests>=2.9.1",
+        "ruamel.yaml>=0.13.2",
+        "tornado>=4.3",
+        "urwid>=1.3.1",
+        "watchdog>=0.8.3",
+        "brotlipy>=0.5.1",
+        "sortedcontainers>=1.5.4",
         # transitive from cryptography, we just blacklist here.
         # https://github.com/pypa/setuptools/issues/861
-        "setuptools>=11.3, !=29.0.0",
+        "setuptools>=11.3",
     ],
     extras_require={
         ':sys_platform == "win32"': [
-            "pydivert>=2.0.3, <2.1",
+            "pydivert>=2.0.3",
         ],
         ':sys_platform != "win32"': [
         ],
         'dev': [
-            "Flask>=0.10.1, <0.13",
-            "flake8>=3.2.1, <3.4",
-            "mypy>=0.471, <0.480",
-            "rstcheck>=2.2, <4.0",
-            "tox>=2.3, <3",
-            "pytest>=3, <3.1",
-            "pytest-cov>=2.2.1, <3",
-            "pytest-timeout>=1.0.0, <2",
-            "pytest-xdist>=1.14, <2",
-            "pytest-faulthandler>=1.3.0, <2",
-            "sphinx>=1.3.5, <1.6",
-            "sphinx-autobuild>=0.5.2, <0.7",
-            "sphinxcontrib-documentedlist>=0.5.0, <0.6",
-            "sphinx_rtd_theme>=0.1.9, <0.2",
+            "Flask>=0.10.1",
+            "flake8>=3.2.1",
+            "mypy>=0.471",
+            "rstcheck>=2.2",
+            "tox>=2.3",
+            "pytest>=3",
+            "pytest-cov>=2.2.1",
+            "pytest-timeout>=1.0.0",
+            "pytest-xdist>=1.14",
+            "pytest-faulthandler>=1.3.0",
+            "sphinx>=1.3.5",
+            "sphinx-autobuild>=0.5.2",
+            "sphinxcontrib-documentedlist>=0.5.0",
+            "sphinx_rtd_theme>=0.1.9",
         ],
         'contentviews': [
         ],
         'examples': [
-            "beautifulsoup4>=4.4.1, <4.6",
-            "pytz>=2015.07.0, <=2016.10",
-            "Pillow>=3.2, <4.1",
+            "beautifulsoup4>=4.4.1",
+            "pytz>=2015.07.0",
+            "Pillow>=3.2",
         ]
     }
 )
