$NetBSD: patch-configure.py,v 1.3 2024/11/15 10:58:31 adam Exp $

Fix building with ICU 76.

--- configure.py.orig	2024-11-15 10:22:32.878698659 +0000
+++ configure.py
@@ -1829,7 +1829,7 @@ def configure_intl(o):
   elif with_intl == 'system-icu':
     # ICU from pkg-config.
     o['variables']['v8_enable_i18n_support'] = 1
-    pkgicu = pkg_config('icu-i18n')
+    pkgicu = pkg_config(['icu-i18n', 'icu-uc'])
     if not pkgicu[0]:
       error('''Could not load pkg-config data for "icu-i18n".
        See above errors or the README.md.''')
