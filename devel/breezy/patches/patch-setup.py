$NetBSD: patch-setup.py,v 1.1 2024/01/07 15:13:12 rhialto Exp $

Surely this should work in some other way, but without this,
"setup.py build" errors out with "error: invalid command 'build_mo'".

It turns out that the created .po files aren't even installed, so
why bother building them... but if you want to, the code is there,
commened out.

--- setup.py.orig	2023-09-04 16:10:56.000000000 +0000
+++ setup.py
@@ -76,11 +76,16 @@ class build_man(Command):
 ########################
 
 from setuptools.command.build import build
+#save = sys.path
+#sys.path.append("./breezy")
+#from bzr_distutils import build_mo
+#sys.path = save
 
-build.sub_commands.append(('build_mo', lambda _: True))
+# build.sub_commands.append(('build_mo', lambda _: True))
 
 command_classes = {
     'build_man': build_man,
+#    'build_mo': build_mo,
 }
 
 from distutils import log
