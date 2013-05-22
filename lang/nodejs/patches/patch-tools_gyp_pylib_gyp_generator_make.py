$NetBSD: patch-tools_gyp_pylib_gyp_generator_make.py,v 1.1 2013/05/22 15:17:07 mspo Exp $

Add support for NetBSD and DragonFly.
--- tools/gyp/pylib/gyp/generator/make.py.orig	2013-03-28 19:07:52.000000000 +0000
+++ tools/gyp/pylib/gyp/generator/make.py
@@ -1984,7 +1984,7 @@ def GenerateOutput(target_list, target_d
         'flock_index': 2,
         'extra_commands': SHARED_HEADER_SUN_COMMANDS,
     })
-  elif flavor == 'freebsd':
+  elif flavor == 'freebsd' or flavor == 'dragonflybsd' or flavor == 'netbsd':
     # Note: OpenBSD has sysutils/flock. lockf seems to be FreeBSD specific.
     header_params.update({
         'flock': 'lockf',
