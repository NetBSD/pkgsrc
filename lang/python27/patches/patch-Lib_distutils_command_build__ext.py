$NetBSD: patch-Lib_distutils_command_build__ext.py,v 1.1 2018/06/17 19:21:21 adam Exp $

--- Lib/distutils/command/build_ext.py.orig	2014-12-10 15:59:34.000000000 +0000
+++ Lib/distutils/command/build_ext.py
@@ -511,8 +511,19 @@ class build_ext (Command):
         # that go into the mix.
         if ext.extra_objects:
             objects.extend(ext.extra_objects)
+
+        # Two possible sources for extra linker arguments:
+        #   - 'extra_link_args' in Extension object
+        #   - LDFLAGS environment variable
+        # The environment variable should take precedence, and
+        # any sensible compiler will give precedence to later
+        # command line args.  Hence we combine them in order:
         extra_args = ext.extra_link_args or []
 
+        if os.environ.has_key('LDFLAGS'):
+            extra_args = list(extra_args)
+            extra_args.extend(string.split(os.environ['LDFLAGS']))
+
         # Detect target language, if not provided
         language = ext.language or self.compiler.detect_language(sources)
 
