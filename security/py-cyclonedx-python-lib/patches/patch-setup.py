$NetBSD: patch-setup.py,v 1.3 2022/06/13 09:59:01 wiz Exp $

Be less restrictive in dependencies.

--- setup.py.orig	2022-06-10 20:01:07.074393300 +0000
+++ setup.py
@@ -16,7 +16,7 @@ install_requires = \
 ['packageurl-python>=0.9',
  'setuptools>=47.0.0',
  'sortedcontainers>=2.4.0,<3.0.0',
- 'toml>=0.10.0,<0.11.0']
+ 'toml>=0.10.0']
 
 extras_require = \
 {':python_version < "3.8"': ['importlib-metadata>=3.4']}
