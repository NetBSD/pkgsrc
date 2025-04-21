$NetBSD: patch-mesonbuild_linkers_linkers.py,v 1.2 2025/04/21 09:23:45 wiz Exp $

1. Avoid thin archives on SunOS.
2. Always use absolute rpaths (per pkgsrc policy)

--- mesonbuild/linkers/linkers.py.orig	2025-04-03 17:13:56.000000000 +0000
+++ mesonbuild/linkers/linkers.py
@@ -372,7 +372,7 @@ class ArLinker(ArLikeLinker, StaticLinke
         thinargs = ''
         if '[D]' in stdo:
             stdargs += 'D'
-        if '[T]' in stdo:
+        if '[T]' in stdo and not mesonlib.is_sunos():
             thinargs = 'T'
         self.std_args = [stdargs]
         self.std_thin_args = [stdargs + thinargs]
@@ -756,7 +756,7 @@ class GnuLikeDynamicLinkerMixin(DynamicL
         # ...instead of just one single looooong option, like this:
         #
         #   -Wl,-rpath-link,/path/to/folder1:/path/to/folder2:...
-        if self.id in {'ld.bfd', 'ld.gold'} and mesonlib.version_compare(self.version, '<2.28'):
+        if self.id in {'ld.bfd', 'ld.gold'} and mesonlib.version_compare(self.version, '<2.28') or True:
             for p in rpath_paths:
                 args.extend(self._apply_prefix('-rpath-link,' + os.path.join(build_dir, p)))
 
