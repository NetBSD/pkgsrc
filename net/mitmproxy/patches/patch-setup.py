$NetBSD: patch-setup.py,v 1.2 2016/02/11 11:07:58 leot Exp $

Avoid too strict version requirements.

--- setup.py.orig	2015-12-03 17:16:16.000000000 +0000
+++ setup.py
@@ -15,25 +15,25 @@ with open(os.path.join(here, 'README.rst
 # Core dependencies
 deps = {
     "netlib>=%s, <%s" % (version.MINORVERSION, version.NEXT_MINORVERSION),
-    "tornado>=4.3.0, <4.4",
-    "configargparse>=0.10.0, <0.11",
-    "pyperclip>=1.5.22, <1.6",
-    "blinker>=1.4, <1.5",
-    "pyparsing>=2.0.5, <2.1",
-    "html2text==2015.11.4",
-    "construct>=2.5.2, <2.6",
-    "six>=1.10.0, <1.11",
-    "lxml==3.4.4",  # there are no Windows wheels for 3.5!
-    "Pillow>=3.0.0, <3.1",
-    "watchdog>=0.8.3, <0.9",
+    "tornado>=4.3.0",
+    "configargparse>=0.10.0",
+    "pyperclip>=1.5.22",
+    "blinker>=1.4",
+    "pyparsing>=2.0.5",
+    "html2text>=2015.11.4",
+    "construct>=2.5.2",
+    "six>=1.10.0",
+    "lxml>=3.4.4",  # there are no Windows wheels for 3.5!
+    "Pillow>=3.0.0",
+    "watchdog>=0.8.3",
 }
 # A script -> additional dependencies dict.
 scripts = {
     "mitmproxy": {
-        "urwid>=1.3.1, <1.4",
+        "urwid>=1.3.1",
     },
     "mitmdump": {
-        "click>=6.2, <6.3",
+        "click>=6.2",
     },
     "mitmweb": set()
 }
@@ -68,7 +68,7 @@ for script_deps in scripts.values():
     deps.update(script_deps)
 
 if sys.version_info < (3, 4):
-    example_deps.add("enum34>=1.0.4, <1.1")
+    example_deps.add("enum34>=1.0.4")
 
 console_scripts = ["%s = libmproxy.main:%s" % (s, s) for s in scripts.keys()]
 
