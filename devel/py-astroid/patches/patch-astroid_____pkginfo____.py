$NetBSD: patch-astroid_____pkginfo____.py,v 1.1 2019/11/06 12:46:40 adam Exp $

Allow newer six.

--- astroid/__pkginfo__.py.orig	2019-11-06 12:41:35.000000000 +0000
+++ astroid/__pkginfo__.py
@@ -23,7 +23,7 @@ numversion = tuple(int(elem) for elem in
 extras_require = {}
 install_requires = [
     "lazy_object_proxy==1.4.*",
-    "six==1.12",
+    "six>=1.12",
     "wrapt==1.11.*",
     'typed-ast>=1.4.0,<1.5;implementation_name== "cpython" and python_version<"3.8"',
 ]
