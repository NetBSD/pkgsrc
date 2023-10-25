$NetBSD: patch-src_bootstrap_bootstrap.py,v 1.20 2023/10/25 05:50:43 pin Exp $

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
@@ -362,10 +366,16 @@ def default_build_triple(verbose):
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
