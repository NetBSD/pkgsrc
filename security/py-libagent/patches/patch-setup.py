$NetBSD: patch-setup.py,v 1.1 2024/09/21 12:40:17 js Exp $

Remove unused dependencies.

--- setup.py.orig	2024-09-21 12:32:40.928381776 +0000
+++ setup.py
@@ -22,13 +22,11 @@ setup(
         'docutils>=0.14',
         'python-daemon>=2.3.0',
         'wheel>=0.32.3',
-        'backports.shutil_which>=3.5.1',
         'ConfigArgParse>=0.12.1',
         'python-daemon>=2.1.2',
         'ecdsa>=0.13',
         'pynacl>=1.4.0',
         'mnemonic>=0.18',
-        'pymsgbox>=1.0.6',
         'semver>=2.2',
         'unidecode>=0.4.20',
         'pywin32>=300;sys_platform=="win32"'
