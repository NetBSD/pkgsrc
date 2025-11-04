$NetBSD: patch-iconv_setup.py,v 1.1 2025/11/04 20:31:27 dkazankov Exp $

Use C stdlib's libiconv by default on NetBSD

--- iconv/setup.py.orig	2024-07-11 11:49:55.000000000 +0000
+++ iconv/setup.py
@@ -55,6 +55,9 @@
         if 'linux' in config.data['canonical_target'] and \
                 not args.force_libiconv:
             config.set_data('GNATCOLL_ICONV_OPT', '', sub='gprbuild')
+        elif 'netbsd' in config.data['canonical_target'] and \
+                not args.force_libiconv:
+            config.set_data('GNATCOLL_ICONV_OPT', '', sub='gprbuild')
         else:
             config.set_data('GNATCOLL_ICONV_OPT', '-liconv', sub='gprbuild')
 
