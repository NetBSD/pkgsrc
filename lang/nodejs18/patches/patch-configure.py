$NetBSD: patch-configure.py,v 1.3 2024/11/23 11:03:32 adam Exp $

Fix building with ICU 76.

--- configure.py.orig	2024-11-12 00:42:39.000000000 +0000
+++ configure.py
@@ -1763,7 +1763,7 @@ def configure_intl(o):
   elif with_intl == 'system-icu':
     # ICU from pkg-config.
     o['variables']['v8_enable_i18n_support'] = 1
-    pkgicu = pkg_config('icu-i18n')
+    pkgicu = pkg_config(['icu-i18n', 'icu-uc'])
     if not pkgicu[0]:
       error('''Could not load pkg-config data for "icu-i18n".
        See above errors or the README.md.''')
