$NetBSD: patch-site__scons_site__tools_libtool.py,v 1.2 2023/07/29 11:45:43 adam Exp $

Use system libtool (Darwin only).

--- site_scons/site_tools/libtool.py.orig	2023-06-29 13:37:52.000000000 +0000
+++ site_scons/site_tools/libtool.py
@@ -25,7 +25,7 @@ import SCons
 
 def generate(env):
 
-    env["AR"] = "libtool"
+    env["AR"] = "/usr/bin/libtool"
     env["ARCOM"] = "$AR -static -o $TARGET $ARFLAGS $SOURCES"
     env["ARFLAGS"] = ["-s", "-no_warning_for_no_symbols"]
 
