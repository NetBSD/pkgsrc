$NetBSD: patch-astroid_____pkginfo____.py,v 1.3 2020/04/23 08:44:26 adam Exp $

Relax wrapt version requirement.
https://github.com/PyCQA/astroid/issues/768

--- astroid/__pkginfo__.py.orig	2020-04-23 08:41:06.000000000 +0000
+++ astroid/__pkginfo__.py
@@ -24,7 +24,7 @@ extras_require = {}
 install_requires = [
     "lazy_object_proxy==1.4.*",
     "six~=1.12",
-    "wrapt==1.11.*",
+    "wrapt>=1.11",
     'typed-ast>=1.4.0,<1.5;implementation_name== "cpython" and python_version<"3.8"',
 ]
 
