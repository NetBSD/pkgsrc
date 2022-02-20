$NetBSD: patch-setup.py,v 1.2 2022/02/20 21:23:44 wiz Exp $

Be less restrictive in dependencies.

--- setup.py.orig	2022-01-24 13:30:26.931830600 +0000
+++ setup.py
@@ -15,9 +15,9 @@ package_data = \
 install_requires = \
 ['packageurl-python>=0.9',
  'setuptools>=47.0.0',
- 'toml>=0.10.0,<0.11.0',
+ 'toml>=0.10.0',
  'types-setuptools>=57.0.0',
- 'types-toml>=0.10.0,<0.11.0']
+ 'types-toml>=0.10.0']
 
 extras_require = \
 {':python_version < "3.8"': ['importlib-metadata>=3.4',
