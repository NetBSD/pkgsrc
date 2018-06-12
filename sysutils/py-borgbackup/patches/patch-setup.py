$NetBSD: patch-setup.py,v 1.4 2018/06/12 14:22:25 bsiegert Exp $

Use latest msgpack version

--- setup.py.orig	2018-06-11 10:55:36.000000000 +0000
+++ setup.py
@@ -39,7 +39,7 @@ install_requires = [
     # we are rather picky about msgpack versions, because a good working msgpack is
     # very important for borg, see https://github.com/borgbackup/borg/issues/3753
     # best versions seem to be 0.4.6, 0.4.7, 0.4.8 and 0.5.6:
-    'msgpack-python >=0.4.6, <=0.5.6, !=0.5.0, !=0.5.1, !=0.5.2, !=0.5.3, !=0.5.4, !=0.5.5',
+    'msgpack >=0.4.6, <=0.5.6, !=0.5.0, !=0.5.1, !=0.5.2, !=0.5.3, !=0.5.4, !=0.5.5',
     # if you can't satisfy the above requirement, these are versions that might
     # also work ok, IF you make sure to use the COMPILED version of msgpack-python,
     # NOT the PURE PYTHON fallback implementation: ==0.5.1, ==0.5.4
