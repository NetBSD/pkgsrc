$NetBSD: patch-setup.py,v 1.3 2021/12/07 10:51:22 khorben Exp $

Override some version checks

--- setup.py.orig	2021-05-10 09:44:33.000000000 +0000
+++ setup.py
@@ -19,7 +19,7 @@ import octoprint_setuptools  # noqa: F40
 PYTHON_REQUIRES = ">=2.7.9, !=3.0.*, !=3.1.*, !=3.2.*, !=3.3.*, !=3.4.*, !=3.5.*, <4"
 
 # Requirements for setup.py
-SETUP_REQUIRES = ["markdown>=3.1,<3.2"]  # newer versions require Python 3
+SETUP_REQUIRES = ["markdown>=3.1"]  # newer versions require Python 3
 
 # Requirements for our application
 INSTALL_REQUIRES = [
@@ -32,7 +32,7 @@ INSTALL_REQUIRES = [
     # other observed problems
     "markupsafe>=1.1,<2.0",  # Jinja dependency, newer versions require Python 3
     "tornado==5.1.1",  # newer versions require Python 3
-    "markdown>=3.1,<3.2",  # newer versions require Python 3
+    "markdown>=3.1",  # newer versions require Python 3
     "regex!=2018.11.6",  # avoid broken 2018.11.6. See #2874
     # anything below this should be checked on releases for new versions
     "flask>=1.1.2,<2",
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
@@ -59,11 +59,11 @@ INSTALL_REQUIRES = [
     "websocket-client>=0.57,<1",
     "wrapt>=1.12.1,<2",
     "emoji>=0.5.4,<1",
-    "sentry-sdk>=0.15.1,<1",
+    "sentry-sdk>=0.15.1",
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
