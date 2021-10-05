$NetBSD: patch-Lib_distutils_command_install.py,v 1.1 2021/10/05 19:07:13 adam Exp $

--- Lib/distutils/command/install.py.orig	2021-07-10 00:51:07.000000000 +0000
+++ Lib/distutils/command/install.py
@@ -675,5 +675,6 @@ class install(Command):
                     ('install_headers', has_headers),
                     ('install_scripts', has_scripts),
                     ('install_data',    has_data),
-                    ('install_egg_info', lambda self:True),
                    ]
+    if not os.environ.get('PKGSRC_PYTHON_NO_EGG'):
+        sub_commands += [('install_egg_info', lambda self:True),]
