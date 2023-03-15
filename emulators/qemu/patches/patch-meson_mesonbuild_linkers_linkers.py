$NetBSD: patch-meson_mesonbuild_linkers_linkers.py,v 1.1 2023/03/15 11:49:20 jperkin Exp $

qemu ships its own version of meson for some strange reason so we need to
apply the same patch here too to avoid thin archives.

--- meson/mesonbuild/linkers/linkers.py.orig	2022-12-14 16:29:34.000000000 +0000
+++ meson/mesonbuild/linkers/linkers.py
@@ -197,7 +197,7 @@ class ArLinker(ArLikeLinker):
         thinargs = ''
         if '[D]' in stdo:
             stdargs += 'D'
-        if '[T]' in stdo:
+        if '[T]' in stdo and not mesonlib.is_sunos():
             thinargs = 'T'
         self.std_args = [stdargs]
         self.std_thin_args = [stdargs + thinargs]
