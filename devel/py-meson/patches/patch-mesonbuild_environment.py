$NetBSD: patch-mesonbuild_environment.py,v 1.5 2019/08/23 15:21:59 nia Exp $

Support NetBSD aarch64 and earm.

Support SunOS ar and SunOS-specific GCC behaviour.

--- mesonbuild/environment.py.orig	2019-07-09 16:34:42.000000000 +0000
+++ mesonbuild/environment.py
@@ -215,6 +215,10 @@ def detect_cpu_family(compilers: Compile
     """
     if mesonlib.is_windows():
         trial = detect_windows_arch(compilers)
+    elif platform.system() == 'NetBSD':
+        # platform.machine() returns the "machine type" on NetBSD, not CPU
+        # family, e.g. 'evbarm' is returned on aarch64.
+        trial = platform.processor().lower()
     else:
         trial = platform.machine().lower()
     if trial.startswith('i') and trial.endswith('86'):
@@ -224,7 +228,7 @@ def detect_cpu_family(compilers: Compile
     # OpenBSD's 64 bit arm architecute identifies as 'arm64'
     elif trial == 'arm64':
         trial = 'aarch64'
-    elif trial.startswith('arm'):
+    elif trial.startswith('arm') or trial.startswith('earm'):
         trial = 'arm'
     elif trial.startswith('ppc64'):
         trial = 'ppc64'
@@ -271,6 +275,10 @@ def detect_cpu_family(compilers: Compile
 def detect_cpu(compilers: CompilersDict):
     if mesonlib.is_windows():
         trial = detect_windows_arch(compilers)
+    elif platform.system() == 'NetBSD':
+        # platform.machine() returns the "machine type" on NetBSD, not CPU
+        # family, e.g. 'evbarm' is returned on aarch64.
+        trial = platform.processor().lower()
     else:
         trial = platform.machine().lower()
     if trial in ('amd64', 'x64'):
@@ -283,6 +291,8 @@ def detect_cpu(compilers: CompilersDict)
         # Same check as above for cpu_family
         if any_compiler_has_define(compilers, '__arm__'):
             trial = 'arm'
+    elif trial.startswith('earm'):
+            trial = 'arm'
     elif trial == 'e2k':
         # Make more precise CPU detection for Elbrus platform.
         trial = platform.processor().lower()
@@ -613,6 +623,8 @@ class Environment:
             return CompilerType.GCC_MINGW
         elif '__CYGWIN__' in defines:
             return CompilerType.GCC_CYGWIN
+        elif '__sun' in defines:
+            return CompilerType.GCC_SUNOS
         return CompilerType.GCC_STANDARD
 
     def _get_compilers(self, lang, for_machine):
@@ -1220,6 +1232,8 @@ class Environment:
                 return ArLinker(linker)
             if p.returncode == 1 and err.startswith('usage'): # OSX
                 return ArLinker(linker)
+            if p.returncode == 1 and err.startswith('ar: bad option'): # SUNOS
+                return ArLinker(linker)
             if p.returncode == 1 and err.startswith('Usage'): # AIX
                 return ArLinker(linker)
             if p.returncode == 1 and err.startswith('ar: bad option: --'): # Solaris
