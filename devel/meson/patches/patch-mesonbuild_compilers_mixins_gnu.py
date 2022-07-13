$NetBSD: patch-mesonbuild_compilers_mixins_gnu.py,v 1.3 2022/07/13 03:57:22 triaxx Exp $

Do not default to -z ignore on SunOS, it breaks for example -fstack-protector.

--- mesonbuild/compilers/mixins/gnu.py.orig	2021-02-08 21:39:00.000000000 +0000
+++ mesonbuild/compilers/mixins/gnu.py
@@ -147,7 +147,7 @@ class GnuLikeCompiler(Compiler, metaclas
                                    'b_ndebug', 'b_staticpic', 'b_pie']}
         if not (self.info.is_windows() or self.info.is_cygwin() or self.info.is_openbsd()):
             self.base_options.add(OptionKey('b_lundef'))
-        if not self.info.is_windows() or self.info.is_cygwin():
+        if not (self.info.is_windows() or self.info.is_sunos()) or self.info.is_cygwin():
             self.base_options.add(OptionKey('b_asneeded'))
         if not self.info.is_hurd():
             self.base_options.add(OptionKey('b_sanitize'))
