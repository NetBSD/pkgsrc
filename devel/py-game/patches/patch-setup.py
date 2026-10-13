$NetBSD: patch-setup.py,v 1.1 2026/10/13 09:06:47 wiz Exp $

Pass compiler flags properly.
https://github.com/pygame/pygame/issues/4716

--- setup.py.orig	2024-09-29 12:15:28.001112000 +0000
+++ setup.py
@@ -123,10 +123,13 @@ if os.environ.get('PYGAME_DETECT_AVX2', '') != '':
                     # filename is found, no need to search any further
                     break
 
-        distutils.ccompiler.spawn(cmd, dry_run=self.dry_run, **kwargs)
+        compile_cmd(self, cmd, **kwargs)
 
-    distutils.ccompiler.CCompiler.__spawn = distutils.ccompiler.CCompiler.spawn
-    distutils.ccompiler.CCompiler.spawn = spawn
+    # setuptools' bundled distutils runs the compiler through Compiler.call();
+    # older distutils used spawn(). Hook whichever one compiles.
+    hook_name = 'call' if hasattr(distutils.ccompiler.CCompiler, 'call') else 'spawn'
+    compile_cmd = getattr(distutils.ccompiler.CCompiler, hook_name)
+    setattr(distutils.ccompiler.CCompiler, hook_name, spawn)
 
 # A (bit hacky) fix for https://github.com/pygame/pygame/issues/2613
 # This is due to the fact that distutils uses command line args to
