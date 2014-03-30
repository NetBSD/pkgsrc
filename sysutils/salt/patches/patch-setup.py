$NetBSD: patch-setup.py,v 1.4 2014/03/30 12:31:17 imil Exp $

Install manpages in man/, not share/man/

--- setup.py.orig	2014-03-19 04:30:45.000000000 +0000
+++ setup.py
@@ -452,12 +452,12 @@ SETUP_KWARGS = {'name': NAME,
                                     'virt/*.jinja'
                                     ],
                                 },
-                'data_files': [('share/man/man1',
+                'data_files': [('man/man1',
                                 ['doc/man/salt-cp.1',
                                  'doc/man/salt-call.1',
                                  'doc/man/salt-minion.1',
                                  ]),
-                               ('share/man/man7',
+                               ('man/man7',
                                 ['doc/man/salt.7',
                                  ]),
                                ],
