$NetBSD: patch-src_bootstrap_bootstrap.py,v 1.19 2023/10/10 13:12:33 pin Exp $

Use `uname -p` on NetBSD, as that is reliable and sensible there.
Handle earmv[67]hf for NetBSD.

--- src/bootstrap/bootstrap.py.orig	2023-07-12 03:32:40.000000000 +0000
+++ src/bootstrap/bootstrap.py
@@ -268,6 +268,10 @@ def default_build_triple(verbose):
         'NetBSD': 'unknown-netbsd',
         'OpenBSD': 'unknown-openbsd'
     }
+    # For NetBSD, use `uname -p`, as there it is reliable & sensible
+    if kernel == 'NetBSD':
+        cputype = subprocess.check_output(
+            ['uname', '-p']).strip().decode(default_encoding)
 
     # Consider the direct transformation first and then the special cases
     if kernel in kerneltype_mapper:
@@ -323,6 +327,7 @@ def default_build_triple(verbose):
     cputype_mapper = {
         'BePC': 'i686',
         'aarch64': 'aarch64',
+        'aarch64eb': 'aarch64',
         'amd64': 'x86_64',
         'arm64': 'aarch64',
         'i386': 'i686',
@@ -361,10 +366,16 @@ def default_build_triple(verbose):
             kernel = 'linux-androideabi'
         else:
             kernel += 'eabihf'
-    elif cputype in {'armv7l', 'armv8l'}:
+    elif cputype in {'armv6hf', 'earmv6hf'}:
+        cputype = 'armv6'
+        if kernel == 'unknown-netbsd':
+            kernel += '-eabihf'
+    elif cputype in {'armv7l', 'earmv7hf', 'armv8l'}:
         cputype = 'armv7'
         if kernel == 'linux-android':
             kernel = 'linux-androideabi'
+        elif kernel == 'unknown-netbsd':
+            kernel += '-eabihf'
         else:
             kernel += 'eabihf'
     elif cputype == 'mips':
