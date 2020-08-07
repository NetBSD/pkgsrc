$NetBSD: patch-mesonbuild_compilers_mixins_gnu.py,v 1.1 2020/08/07 13:04:08 jperkin Exp $

Do not default to -z ignore on SunOS, it breaks for example -fstack-protector.

--- mesonbuild/compilers/mixins/gnu.py.orig	2020-06-29 17:00:07.000000000 +0000
+++ mesonbuild/compilers/mixins/gnu.py
@@ -144,7 +144,7 @@ class GnuLikeCompiler(metaclass=abc.ABCM
                              'b_ndebug', 'b_staticpic', 'b_pie']
         if not (self.info.is_windows() or self.info.is_cygwin() or self.info.is_openbsd()):
             self.base_options.append('b_lundef')
-        if not self.info.is_windows() or self.info.is_cygwin():
+        if not (self.info.is_windows() or self.info.is_sunos()) or self.info.is_cygwin():
             self.base_options.append('b_asneeded')
         if not self.info.is_hurd():
             self.base_options.append('b_sanitize')
