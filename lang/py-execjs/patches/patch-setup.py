$NetBSD: patch-setup.py,v 1.1 2017/07/28 07:01:31 adam Exp $

Allow newer version of six.

--- setup.py.orig	2017-07-28 06:58:53.000000000 +0000
+++ setup.py
@@ -39,6 +39,6 @@ setup(
         'Programming Language :: Python :: 3.5',
         'Programming Language :: JavaScript',
     ],
-    install_requires=["six==1.10.0"],
+    install_requires=["six>=1.10.0"],
     test_suite="test_execjs",
 )
