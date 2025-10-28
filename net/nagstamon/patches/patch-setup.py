$NetBSD: patch-setup.py,v 1.4 2025/10/28 11:36:18 bouyer Exp $

Fix paths for pkgsrc

--- setup.py.orig	2025-03-14 14:32:29.956473467 +0100
+++ setup.py	2025-03-14 14:37:36.786709617 +0100
@@ -153,9 +153,9 @@
                                   'resources/qui/*',
                                   'resources/LICENSE',
                                   'resources/CREDITS']},
-      data_files=[('%s/share/man/man1' % sys.prefix, ['Nagstamon/resources/nagstamon.1.gz']),
-                  ('%s/share/pixmaps' % sys.prefix, ['Nagstamon/resources/nagstamon.svg']),
-                  ('%s/share/applications' % sys.prefix, ['Nagstamon/resources/nagstamon.desktop'])],
+      data_files=[('@PKGMANDIR@/man1', ['Nagstamon/resources/nagstamon.1.gz']),
+                  ('share/pixmaps', ['Nagstamon/resources/nagstamon.svg']),
+                  ('share/applications', ['Nagstamon/resources/nagstamon.desktop'])],
       options=dict(build_exe=build_exe_options,
                    bdist_mac=bdist_mac_options,
                    bdist_dmg=bdist_dmg_options,
