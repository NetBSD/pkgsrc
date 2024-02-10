$NetBSD: patch-build__tools_mozc__version.py,v 1.1 2024/02/10 01:20:46 ryoon Exp $

* NetBSD support

--- build_tools/mozc_version.py.orig	2021-02-15 03:48:53.000000000 +0000
+++ build_tools/mozc_version.py
@@ -69,6 +69,7 @@ TARGET_PLATFORM_TO_DIGIT = {
     'iOS': '6',
     'iOS_sim': '6',
     'Wasm': '7',
+    'NetBSD': '8',
 }
 
 VERSION_PROPERTIES = [
