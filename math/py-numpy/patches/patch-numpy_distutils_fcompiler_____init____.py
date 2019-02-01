$NetBSD: patch-numpy_distutils_fcompiler_____init____.py,v 1.1 2019/02/01 09:24:25 adam Exp $

Recognize g95.

--- numpy/distutils/fcompiler/__init__.py.orig	2013-04-07 05:04:05.000000000 +0000
+++ numpy/distutils/fcompiler/__init__.py
@@ -756,7 +756,7 @@ _default_compilers = (
     ('irix.*', ('mips', 'gnu', 'gnu95',)),
     ('aix.*', ('ibm', 'gnu', 'gnu95',)),
     # os.name mappings
-    ('posix', ('gnu', 'gnu95',)),
+    ('posix', ('gnu', 'gnu95', 'g95',)),
     ('nt', ('gnu', 'gnu95',)),
     ('mac', ('gnu95', 'gnu', 'pg')),
     )
