$NetBSD: patch-setup.py,v 1.4 2026/02/17 15:27:36 wiz Exp $

Remove ez_setup.py use, pkgsrc will provide setuptools:
https://github.com/dropbox/dropbox-sdk-python/issues/525

Unpin stone.

Remove unused pytest-runner dependency.

--- setup.py.orig	2024-06-03 16:45:16.000000000 +0000
+++ setup.py
@@ -6,15 +6,6 @@ import sys
 import os
 import sys
 
-# Ensure setuptools is available
-try:
-    from ez_setup import use_setuptools
-    use_setuptools()
-except ImportError:
-    # Try to use ez_setup, but if not, continue anyway. The import is known
-    # to fail when installing from a tar.gz.
-    print('Could not import ez_setup', file=sys.stderr)
-
 from setuptools import setup
 
 dbx_mod_path = os.path.join(os.path.dirname(__file__), 'dropbox/dropbox_client.py')
@@ -27,13 +18,10 @@ install_reqs = [
 install_reqs = [
     'requests>=2.16.2',
     'six >= 1.12.0',
-    'stone>=2,<3.3.3',
+    'stone>=2',
 ]
 
 setup_requires = [
-    # Pin pytest-runner to 5.2.0, since 5.3.0 uses `find_namespaces` directive, not supported in
-    # Python 2.7
-    'pytest-runner==5.2.0',
 ]
 
 # WARNING: This imposes limitations on test/requirements.txt such that the
