$NetBSD: patch-setup.py,v 1.1 2023/06/11 15:13:47 wiz Exp $

Do not build c-extension; remove when Python 3.11 gets supported.

--- setup.py.orig	2023-04-29 20:10:14.000000000 +0000
+++ setup.py
@@ -203,6 +203,7 @@ if custom_arg == None:
 elif custom_arg in custom_args_c:
     optional = False
 
+custom_arg = "py"
 if custom_arg in custom_args_py:
     setuptools.setup(**common_setup_args)
 elif custom_arg in custom_args_c:
