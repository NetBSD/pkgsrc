$NetBSD: patch-astroid_____pkginfo____.py,v 1.5 2020/07/15 09:19:05 adam Exp $

Allow newer lazy_object_proxy.

--- astroid/__pkginfo__.py.orig	2020-07-15 09:05:17.000000000 +0000
+++ astroid/__pkginfo__.py
@@ -26,7 +26,7 @@ numversion = tuple(int(elem) for elem in
 
 extras_require = {}
 install_requires = [
-    "lazy_object_proxy==1.4.*",
+    "lazy_object_proxy>=1.4.0",
     "six~=1.12",
     "wrapt~=1.11",
     'typed-ast>=1.4.0,<1.5;implementation_name== "cpython" and python_version<"3.8"',
