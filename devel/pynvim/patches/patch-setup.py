$NetBSD: patch-setup.py,v 1.1 2024/08/10 15:32:37 wiz Exp $

https://github.com/neovim/pynvim/issues/572

--- setup.py.orig	2024-08-10 15:22:38.466795284 +0000
+++ setup.py
@@ -16,7 +16,7 @@ needs_pytest = {'pytest', 'test', 'ptr'}
 pytest_runner = ['pytest-runner'] if needs_pytest else []
 
 setup_requires = [
-] + pytest_runner
+]
 
 tests_require = [
     'pytest',
