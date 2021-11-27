$NetBSD: patch-setup.py,v 1.1 2021/11/27 18:29:48 wiz Exp $

2to3 is not needed any longer.

--- setup.py.orig	2019-05-09 22:49:51.000000000 +0000
+++ setup.py
@@ -62,5 +62,4 @@ setup(
         'Topic :: Software Development :: Libraries',
         'Topic :: System :: Hardware :: Hardware Drivers',
     ],
-    use_2to3=sys.version_info >= (3, ),
 )
