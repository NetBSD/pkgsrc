$NetBSD: patch-Lib_distutils_command_install.py,v 1.1 2015/12/05 17:12:13 adam Exp $

--- Lib/distutils/command/install.py.orig	2012-02-23 20:22:44.000000000 +0000
+++ Lib/distutils/command/install.py
@@ -676,5 +676,6 @@ class install(Command):
                     ('install_headers', has_headers),
                     ('install_scripts', has_scripts),
                     ('install_data',    has_data),
-                    ('install_egg_info', lambda self:True),
                    ]
+    if not os.environ.get('PKGSRC_PYTHON_NO_EGG'):
+        sub_commands += [('install_egg_info', lambda self:True),]
