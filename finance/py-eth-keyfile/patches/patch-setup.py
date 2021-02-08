$NetBSD: patch-setup.py,v 1.1 2021/02/08 07:02:27 adam Exp $

setuptools-markdown is deprecated.

--- setup.py.orig	2018-02-13 17:56:42.000000000 +0000
+++ setup.py
@@ -19,7 +19,8 @@ setup(
         "A library for handling the encrypted keyfiles used to store ethereum "
         "private keys."
     ),
-    long_description_markdown_filename='README.md',
+    long_description='README.md',
+    long_description_content_type="text/markdown",
     author='Piper Merriam',
     author_email='pipermerriam@gmail.com',
     url='https://github.com/ethereum/eth-keyfile',
@@ -30,7 +31,6 @@ setup(
         "cytoolz>=0.9.0,<1.0.0",
         "pycryptodome>=3.4.7,<4.0.0",
     ],
-    setup_requires=['setuptools-markdown'],
     py_modules=['eth_keyfile'],
     license="MIT",
     zip_safe=False,
