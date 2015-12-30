$NetBSD: patch-setup.py,v 1.1 2015/12/30 15:08:08 leot Exp $

Avoid too strict version requirements.

--- setup.py.orig	2015-12-03 17:16:16.000000000 +0000
+++ setup.py
@@ -20,10 +20,10 @@ deps = {
     "pyperclip>=1.5.22, <1.6",
     "blinker>=1.4, <1.5",
     "pyparsing>=2.0.5, <2.1",
-    "html2text==2015.11.4",
+    "html2text>=2015.11.4",
     "construct>=2.5.2, <2.6",
     "six>=1.10.0, <1.11",
-    "lxml==3.4.4",  # there are no Windows wheels for 3.5!
+    "lxml>=3.4.4",  # there are no Windows wheels for 3.5!
     "Pillow>=3.0.0, <3.1",
     "watchdog>=0.8.3, <0.9",
 }
