$NetBSD: patch-setup.py,v 1.1 2018/01/23 09:50:18 wiz Exp $

msgpack distribution changed name.

--- setup.py.orig	2017-12-30 09:14:25.000000000 +0000
+++ setup.py
@@ -37,7 +37,7 @@ on_rtd = os.environ.get('READTHEDOCS')
 
 # msgpack pure python data corruption was fixed in 0.4.6.
 # Also, we might use some rather recent API features.
-install_requires = ['msgpack-python>=0.4.6', ]
+install_requires = ['msgpack>=0.4.6', ]
 
 # note for package maintainers: if you package borgbackup for distribution,
 # please add llfuse as a *requirement* on all platforms that have a working
