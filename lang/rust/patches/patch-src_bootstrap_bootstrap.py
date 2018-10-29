$NetBSD: patch-src_bootstrap_bootstrap.py,v 1.2 2018/10/29 22:24:11 he Exp $

Use `uname -p` on NetBSD, as that's reliable & sensible there.
Also force debuginfo to 0, otherwise the build doesn't work on
NetBSD/macppc (powerpc).
Also, handle earmv7hf for NetBSD.

--- src/bootstrap/bootstrap.py.orig	2018-09-20 17:28:03.000000000 +0000
+++ src/bootstrap/bootstrap.py
@@ -196,6 +196,11 @@ def default_build_triple():
         'OpenBSD': 'unknown-openbsd'
     }
 
+    # For NetBSD, use `uname -p`, as there it is reliable & sensible
+    if ostype == 'NetBSD':
+        cputype = subprocess.check_output(
+            ['uname', '-p']).strip().decode(default_encoding)
+
     # Consider the direct transformation first and then the special cases
     if ostype in ostype_mapper:
         ostype = ostype_mapper[ostype]
@@ -275,10 +280,12 @@ def default_build_triple():
             ostype = 'linux-androideabi'
         else:
             ostype += 'eabihf'
-    elif cputype in {'armv7l', 'armv8l'}:
+    elif cputype in {'armv7l', 'armv8l', 'earmv7hf'}:
         cputype = 'armv7'
         if ostype == 'linux-android':
             ostype = 'linux-androideabi'
+        elif ostype == 'unknown-netbsd':
+            ostype += '-eabihf'
         else:
             ostype += 'eabihf'
     elif cputype == 'mips':
