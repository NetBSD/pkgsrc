$NetBSD: patch-setup.py,v 1.3 2016/02/16 13:54:00 leot Exp $

Avoid too strict version requirements.

--- setup.py.orig	2016-02-14 16:04:47.000000000 +0000
+++ setup.py
@@ -51,19 +51,19 @@ setup(
     # It is not considered best practice to use install_requires to pin dependencies to specific versions.
     install_requires=[
         "netlib>={}, <{}".format(version.MINORVERSION, version.NEXT_MINORVERSION),
-        "h2>=2.1.0, <2.2",
-        "tornado>=4.3, <4.4",
-        "configargparse>=0.10, <0.11",
-        "pyperclip>=1.5.22, <1.6",
-        "blinker>=1.4, <1.5",
-        "pyparsing>=2.1,<2.2",
-        "html2text==2016.1.8",
-        "construct>=2.5.2, <2.6",
-        "six>=1.10, <1.11",
-        "Pillow>=3.1, <3.2",
-        "watchdog>=0.8.3, <0.9",
-        "click>=6.2, <7.0",
-        "urwid>=1.3.1, <1.4",
+        "h2>=2.1.0",
+        "tornado>=4.3",
+        "configargparse>=0.10",
+        "pyperclip>=1.5.22",
+        "blinker>=1.4",
+        "pyparsing>=2.1",
+        "html2text>=2016.1.8",
+        "construct>=2.5.2",
+        "six>=1.10",
+        "Pillow>=3.1",
+        "watchdog>=0.8.3",
+        "click>=6.2",
+        "urwid>=1.3.1",
     ],
     extras_require={
         ':sys_platform == "win32"': [
@@ -71,34 +71,34 @@ setup(
             "lxml==3.4.4",  # there are no Windows wheels for newer versions, so we pin this.
         ],
         ':sys_platform != "win32"': [
-            "lxml>=3.5.0, <3.6",
+            "lxml>=3.5.0",
         ],
         # Do not use a range operator here: https://bitbucket.org/pypa/setuptools/issues/380
         # Ubuntu Trusty and other still ship with setuptools < 17.1
         ':python_version == "2.7"': [
-            "enum34>=1.0.4, <1.2",
+            "enum34>=1.0.4",
         ],
         'dev': [
-            "mock>=1.3.0, <1.4",
-            "pytest>=2.8.7, <2.9",
-            "pytest-xdist>=1.14, <1.15",
-            "pytest-cov>=2.2.1, <2.3",
-            "pytest-timeout>=1.0.0, <1.1",
-            "coveralls>=1.1, <1.2",
+            "mock>=1.3.0",
+            "pytest>=2.8.7",
+            "pytest-xdist>=1.14",
+            "pytest-cov>=2.2.1",
+            "pytest-timeout>=1.0.0",
+            "coveralls>=1.1",
             "pathod>={}, <{}".format(version.MINORVERSION, version.NEXT_MINORVERSION),
-            "sphinx>=1.3.5, <1.4",
-            "sphinx-autobuild>=0.5.2, <0.6",
-            "sphinxcontrib-documentedlist>=0.3.0, <0.4"
+            "sphinx>=1.3.5",
+            "sphinx-autobuild>=0.5.2",
+            "sphinxcontrib-documentedlist>=0.3.0",
         ],
         'contentviews': [
-            "pyamf>=0.8.0, <0.9",
-            "protobuf>=2.6.1, <2.7",
-            "cssutils>=1.0.1, <1.1"
+            "pyamf>=0.8.0",
+            "protobuf>=2.6.1",
+            "cssutils>=1.0.1",
         ],
         'examples': [
             "pytz==2015.7.0",
-            "harparser>=0.2, <0.3",
-            "beautifulsoup4>=4.4.1, <4.5",
+            "harparser>=0.2",
+            "beautifulsoup4>=4.4.1",
         ]
     }
 )
