$NetBSD: patch-setup.py,v 1.1 2022/01/11 19:21:49 adam Exp $

Allow newer py-packaging.

--- setup.py.orig	2022-01-11 10:51:17.000000000 +0000
+++ setup.py
@@ -41,7 +41,7 @@ install_requires = \
  'cleo>=0.8.1,<0.9.0',
  'clikit>=0.6.2,<0.7.0',
  'html5lib>=1.0,<2.0',
- 'packaging>=20.4,<21.0',
+ 'packaging>=20.4',
  'pexpect>=4.7.0,<5.0.0',
  'pkginfo>=1.4,<2.0',
  'poetry-core>=1.0.7,<1.1.0',
