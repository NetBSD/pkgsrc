$NetBSD: patch-setup.py,v 1.5 2026/09/21 19:05:58 bouyer Exp $

Fix paths for pkgsrc

--- setup.py.orig	2026-03-14 09:57:55.000000000 +0100
+++ setup.py	2026-09-21 15:32:54.141535197 +0200
@@ -155,9 +155,9 @@
                                   'resources/qui/*',
                                   'resources/LICENSE',
                                   'resources/CREDITS']},
-      data_files=[(f'{sys.prefix}/share/man/man1', ['Nagstamon/resources/nagstamon.1.gz']),
-                  (f'{sys.prefix}/share/pixmaps', ['Nagstamon/resources/nagstamon.svg']),
-                  (f'{sys.prefix}/share/applications', ['Nagstamon/resources/nagstamon.desktop'])],
+      data_files=[('@PKGMANDIR@/man1', ['Nagstamon/resources/nagstamon.1.gz']),
+                  ('share/pixmaps', ['Nagstamon/resources/nagstamon.svg']),
+                  ('share/applications', ['Nagstamon/resources/nagstamon.desktop'])],
       options=dict(build_exe=build_exe_options,
                    bdist_mac=bdist_mac_options,
                    bdist_dmg=bdist_dmg_options,
