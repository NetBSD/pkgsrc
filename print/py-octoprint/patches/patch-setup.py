$NetBSD: patch-setup.py,v 1.2 2021/05/30 21:53:11 khorben Exp $

Override some version checks

--- setup.py.orig	2021-05-10 09:44:33.000000000 +0000
+++ setup.py
@@ -46,8 +46,8 @@ INSTALL_REQUIRES = [
     "PyYAML>=5.3.1,<6",
     "pyserial>=3.4,<4",
     "netaddr>=0.7.19,<1",
-    "watchdog==0.10.4",  # watchdog dropped Py>3.6 on 0.10.5 point release...
-    "sarge==0.1.5post0",
+    "watchdog>=0.10.3",  # watchdog dropped Py>3.6 on 0.10.5 point release...
+    "sarge>=0.1.5post0",
     "netifaces>=0.10.9,<1",
     "pylru>=1.2,<2",
     "pkginfo>=1.5.0.1,<2",
@@ -63,7 +63,7 @@ INSTALL_REQUIRES = [
     "filetype>=1.0.7,<2",
     "zipstream-new>=1.1.8,<1.2",
     # vendor bundled dependencies
-    "unidecode>=0.04.14,<0.05",  # dependency of awesome-slugify
+    "unidecode>=0.04.14",  # dependency of awesome-slugify
     "blinker>=1.4,<2",  # dependency of flask_principal
 ]
 
@@ -82,8 +82,8 @@ INSTALL_REQUIRES_PYTHON2 = [
 # Python 3 specific requirements
 INSTALL_REQUIRES_PYTHON3 = [
     "feedparser>=6.0.2,<7",
-    "zeroconf>=0.24,<0.25",
-    "immutabledict>=1.2.0,<2",
+    "zeroconf>=0.24",
+    "immutabledict>=1.2.0",
 ]
 
 # OSX specific requirements
