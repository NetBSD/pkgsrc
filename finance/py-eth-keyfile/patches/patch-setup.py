$NetBSD: patch-setup.py,v 1.3 2022/07/15 20:54:26 adam Exp $

setuptools-markdown is deprecated.

--- setup.py.orig	2022-07-15 20:50:18.000000000 +0000
+++ setup.py
@@ -52,13 +52,13 @@ setup(
         "private keys."
     ),
     long_description_markdown_filename='README.md',
+    long_description_content_type="text/markdown",
     author='Piper Merriam',
     author_email='pipermerriam@gmail.com',
     url='https://github.com/ethereum/eth-keyfile',
     include_package_data=True,
     install_requires=install_requires,
     extras_require=deps,
-    setup_requires=['setuptools-markdown'],
     py_modules=['eth_keyfile'],
     license="MIT",
     zip_safe=False,
