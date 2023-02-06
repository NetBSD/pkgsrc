$NetBSD: patch-setup.py,v 1.1 2023/02/06 11:23:50 nros Exp $

* don't install gzipped manpage in the wrong location,
  BSD_INSTALL will handle it.

--- setup.py.orig	2023-02-06 11:10:28.341558842 +0000
+++ setup.py
@@ -46,6 +46,5 @@ It is released under the GNU GPL license
             'flawfinder = flawfinder:main',
         ],
        },
-       data_files = [ ('share/man/man1', [ 'flawfinder.1.gz' ]) ],
        py_modules = ['flawfinder'],
       )
