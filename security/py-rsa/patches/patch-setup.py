$NetBSD: patch-setup.py,v 1.1 2018/10/19 14:36:10 jperkin Exp $

Pull in fix from https://github.com/sybrenstuvel/python-rsa/pull/122/files

--- setup.py.orig	2018-09-16 11:39:35.000000000 +0000
+++ setup.py
@@ -16,7 +16,7 @@
 
 from setuptools import setup
 
-with open('README.md') as f:
+with open('README.md', 'r', encoding='utf-8') as f:
     long_description = f.read()
 
 if __name__ == '__main__':
