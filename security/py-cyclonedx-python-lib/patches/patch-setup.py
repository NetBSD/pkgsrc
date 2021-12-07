$NetBSD: patch-setup.py,v 1.1 2021/12/07 18:05:29 wiz Exp $

Be less restrictive in dependencies.

--- setup.py.orig	2021-11-10 15:42:02.183635700 +0000
+++ setup.py
@@ -13,12 +13,12 @@ package_data = \
 {'': ['*'], 'cyclonedx': ['schema/*', 'schema/ext/*']}
 
 install_requires = \
-['packageurl-python>=0.9.4,<0.10.0',
- 'requirements_parser>=0.2.0,<0.3.0',
- 'setuptools>=50.3.2,<51.0.0',
- 'toml>=0.10.2,<0.11.0',
- 'types-setuptools>=57.4.2,<58.0.0',
- 'types-toml>=0.10.1,<0.11.0']
+['packageurl-python>=0.9.4',
+ 'requirements_parser>=0.2.0',
+ 'setuptools>=50.3.2',
+ 'toml>=0.10.2',
+ 'types-setuptools>=57.4.2',
+ 'types-toml>=0.10.1']
 
 extras_require = \
 {':python_version >= "3.6" and python_version < "3.8"': ['importlib-metadata>=4.8.1,<5.0.0',
