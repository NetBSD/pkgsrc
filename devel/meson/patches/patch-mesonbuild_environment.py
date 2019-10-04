$NetBSD: patch-mesonbuild_environment.py,v 1.1 2019/10/04 14:06:19 prlw1 Exp $

Support NetBSD aarch64 and earm.
commit 246b49fe75e8f882f26a0551f89c42ca20ee50c2

Support SunOS ar and SunOS-specific GCC behaviour.

--- mesonbuild/environment.py.orig	2019-08-25 19:17:02.000000000 +0000
+++ mesonbuild/environment.py
@@ -215,7 +215,7 @@ def detect_cpu_family(compilers: Compile
     """
     if mesonlib.is_windows():
         trial = detect_windows_arch(compilers)
-    elif mesonlib.is_freebsd() or mesonlib.is_openbsd():
+    elif mesonlib.is_freebsd() or mesonlib.is_netbsd() or mesonlib.is_openbsd():
         trial = platform.processor().lower()
     else:
         trial = platform.machine().lower()
@@ -223,7 +223,7 @@ def detect_cpu_family(compilers: Compile
         trial = 'x86'
     elif trial == 'bepc':
         trial = 'x86'
-    elif trial.startswith('arm'):
+    elif trial.startswith('arm') or trial.startswith('earm'):
         trial = 'arm'
     elif trial.startswith(('powerpc64', 'ppc64')):
         trial = 'ppc64'
@@ -260,7 +260,7 @@ def detect_cpu_family(compilers: Compile
 def detect_cpu(compilers: CompilersDict):
     if mesonlib.is_windows():
         trial = detect_windows_arch(compilers)
-    elif mesonlib.is_freebsd() or mesonlib.is_openbsd():
+    elif mesonlib.is_freebsd() or mesonlib.is_netbsd() or mesonlib.is_openbsd():
         trial = platform.processor().lower()
     else:
         trial = platform.machine().lower()
@@ -274,6 +274,8 @@ def detect_cpu(compilers: CompilersDict)
         # Same check as above for cpu_family
         if any_compiler_has_define(compilers, '__arm__'):
             trial = 'arm'
+    elif trial.startswith('earm'):
+            trial = 'arm'
     elif trial == 'e2k':
         # Make more precise CPU detection for Elbrus platform.
         trial = platform.processor().lower()
@@ -605,6 +607,8 @@ class Environment:
             return CompilerType.GCC_MINGW
         elif '__CYGWIN__' in defines:
             return CompilerType.GCC_CYGWIN
+        elif '__sun' in defines:
+            return CompilerType.GCC_SUNOS
         return CompilerType.GCC_STANDARD
 
     def _get_compilers(self, lang, for_machine):
@@ -1212,6 +1216,8 @@ class Environment:
                 return ArLinker(linker)
             if p.returncode == 1 and err.startswith('usage'): # OSX
                 return ArLinker(linker)
+            if p.returncode == 1 and err.startswith('ar: bad option'): # SUNOS
+                return ArLinker(linker)
             if p.returncode == 1 and err.startswith('Usage'): # AIX
                 return ArLinker(linker)
             if p.returncode == 1 and err.startswith('ar: bad option: --'): # Solaris
