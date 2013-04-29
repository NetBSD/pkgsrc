$NetBSD: patch-build__tools_mozc__version.py,v 1.1 2013/04/29 09:52:17 ryoon Exp $

--- build_tools/mozc_version.py.orig	2012-08-31 05:37:06.000000000 +0000
+++ build_tools/mozc_version.py
@@ -65,6 +65,7 @@ TARGET_PLATFORM_TO_DIGIT = {
     'ChromeOS': '2',
     'Android': '3',
     'NaCl': '4',
+    'NetBSD': '5',
     }
 
 VERSION_PROPERTIES = [
