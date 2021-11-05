$NetBSD: patch-setup.py,v 1.2 2021/11/05 11:01:47 wiz Exp $

Remove upper bound on jedi.

--- setup.py.orig	2020-12-11 19:24:55.000000000 +0000
+++ setup.py
@@ -10,7 +10,7 @@ install_requires = [
         'configparser; python_version<"3.0"',
         'future>=0.14.0; python_version<"3"',
         'backports.functools_lru_cache; python_version<"3.2"',
-        'jedi>=0.17.2,<0.18.0',
+        'jedi>=0.17.2',
         'python-jsonrpc-server>=0.4.0',
         'pluggy',
         'ujson<=2.0.3 ; platform_system!="Windows" and python_version<"3.0"',
