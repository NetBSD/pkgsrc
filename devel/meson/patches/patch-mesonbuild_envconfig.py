$NetBSD: patch-mesonbuild_envconfig.py,v 1.1 2019/10/04 14:06:19 prlw1 Exp $

https://github.com/mesonbuild/meson/issues/5451

--- mesonbuild/envconfig.py.orig	2019-07-09 16:34:42.000000000 +0000
+++ mesonbuild/envconfig.py
@@ -340,6 +340,11 @@ This is probably wrong, it should always
             command = os.environ.get(evar)
             if command is not None:
                 command = shlex.split(command)
+
+        # Do not return empty or blank string entries
+        if command is not None and (len(command) == 0 or len(command[0].strip()) == 0):
+            return None
+
         return command
 
 class Directories:
