$NetBSD: patch-setup.py,v 1.1 2020/08/04 18:05:21 adam Exp $

--- setup.py.orig	2020-08-04 17:57:22.000000000 +0000
+++ setup.py
@@ -49,7 +49,7 @@ setup(name='ncclient',
       author=__author__,
       author_email=__author_email__,
       url="https://github.com/ncclient/ncclient",
-      packages=find_packages('.'),
+      packages=find_packages(exclude=['test', 'test.*']),
       install_requires=install_reqs,
       tests_require=test_reqs,
       license=__licence__,
