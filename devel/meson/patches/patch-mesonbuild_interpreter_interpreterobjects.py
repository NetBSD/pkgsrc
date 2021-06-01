$NetBSD: patch-mesonbuild_interpreter_interpreterobjects.py,v 1.1 2021/06/01 05:55:46 cirnatdan Exp $

Upstream patch, won't be necessary when the next version is released
interpreter: flatten environment() initial values
https://github.com/mesonbuild/meson/pull/8761

--- mesonbuild/interpreter/interpreterobjects.py.orig	2021-04-27 06:49:45.000000000 +0000
+++ mesonbuild/interpreter/interpreterobjects.py
@@ -165,7 +165,9 @@ class EnvironmentVariablesHolder(Mutable
             for k, v in initial_values.items():
                 self.set_method([k, v], {})
         elif initial_values is not None:
-            for e in mesonlib.stringlistify(initial_values):
+            for e in mesonlib.listify(initial_values):
+                if not isinstance(e, str):
+                     raise InterpreterException('Env var definition must be a list of strings.')
                 if '=' not in e:
                     raise InterpreterException('Env var definition must be of type key=val.')
                 (k, val) = e.split('=', 1)
