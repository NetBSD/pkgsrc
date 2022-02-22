$NetBSD: patch-mesonbuild_linkers_linkers.py,v 1.1 2022/02/22 17:56:53 jperkin Exp $

Avoid thin archives on SunOS.

--- mesonbuild/linkers/linkers.py.orig	2022-01-02 20:12:32.000000000 +0000
+++ mesonbuild/linkers/linkers.py
@@ -197,7 +197,7 @@ class ArLinker(ArLikeLinker):
         thinargs = ''
         if '[D]' in stdo:
             stdargs += 'D'
-        if '[T]' in stdo:
+        if '[T]' in stdo and not mesonlib.is_sunos():
             thinargs = 'T'
         self.std_args = [stdargs]
         self.std_thin_args = [stdargs + thinargs]
