$NetBSD: patch-setup.py,v 1.1 2019/01/08 09:17:37 adam Exp $

CHANGES.txt does not exist.

--- setup.py.orig	2019-01-08 09:15:13.000000000 +0000
+++ setup.py
@@ -16,14 +16,13 @@ else:
 
 here = os.path.abspath(os.path.dirname(__file__))
 README = open(os.path.join(here, 'README.txt')).read()
-CHANGES = open(os.path.join(here, 'CHANGES.txt')).read()
 
 setup(
     name='pkginfo',
     version='1.5.0',
     description='Query metadatdata from sdists / bdists / installed packages.',
     platforms=['Unix', 'Windows'],
-    long_description='\n\n'.join([README, CHANGES]),
+    long_description=README,
     keywords='distribution sdist installed metadata',
     url='https://code.launchpad.net/~tseaver/pkginfo/trunk',
     author='Tres Seaver, Agendaless Consulting',
