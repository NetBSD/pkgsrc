$NetBSD: patch-setup.py,v 1.2 2018/10/23 09:55:09 jperkin Exp $

Pull in fix from https://github.com/sybrenstuvel/python-rsa/pull/122/files

--- setup.py.orig	2018-09-16 11:39:35.000000000 +0000
+++ setup.py
@@ -15,8 +15,9 @@
 #  limitations under the License.
 
 from setuptools import setup
+from io import open
 
-with open('README.md') as f:
+with open('README.md', 'r', encoding='utf-8') as f:
     long_description = f.read()
 
 if __name__ == '__main__':
