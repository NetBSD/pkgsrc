$NetBSD: patch-setup.py,v 1.1 2022/11/14 19:01:22 wiz Exp $

'U' flag was deprecated.

--- setup.py.orig	2018-06-16 22:21:26.000000000 +0000
+++ setup.py
@@ -17,7 +17,7 @@ trove_classifiers = [
 setup(name="magic-wormhole-mailbox-server",
       version=versioneer.get_version(),
       description="Securely transfer data between computers",
-      long_description=open('README.md', 'rU').read(),
+      long_description=open('README.md', 'r').read(),
       long_description_content_type='text/markdown',
       author="Brian Warner",
       author_email="warner-magic-wormhole@lothar.com",
