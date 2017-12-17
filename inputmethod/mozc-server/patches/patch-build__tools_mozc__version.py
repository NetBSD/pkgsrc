$NetBSD: patch-build__tools_mozc__version.py,v 1.3 2017/12/17 14:15:43 tsutsui Exp $

* NetBSD support

--- build_tools/mozc_version.py.orig	2014-01-06 07:10:26.000000000 +0000
+++ build_tools/mozc_version.py
@@ -64,6 +64,7 @@ TARGET_PLATFORM_TO_DIGIT = {
     'Linux': '2',
     'Android': '3',
     'NaCl': '4',
+    'NetBSD': '5',
     }
 
 VERSION_PROPERTIES = [
