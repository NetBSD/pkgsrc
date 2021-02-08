$NetBSD: patch-setup.py,v 1.1 2021/02/08 07:00:56 adam Exp $

setuptools-markdown is deprecated.

--- setup.py.orig	2021-02-08 06:23:00.000000000 +0000
+++ setup.py
@@ -45,12 +45,12 @@ setup(
     # *IMPORTANT*: Don't manually change the version here. Use the 'bumpversion' utility.
     version='0.3.3',
     description="""Common API for Ethereum key operations.""",
-    long_description_markdown_filename='README.md',
+    long_description='README.md',
+    long_description_content_type="text/markdown",
     author='Piper Merriam',
     author_email='pipermerriam@gmail.com',
     url='https://github.com/ethereum/eth-keys',
     include_package_data=True,
-    setup_requires=['setuptools-markdown'],
     install_requires=deps['eth-keys'],
     py_modules=['eth_keys'],
     extras_require=deps,
