$NetBSD: patch-mcomix_run.py,v 1.1 2019/05/18 08:30:20 wiz Exp $

Fix incompatibility with PIL 6.0.0.
https://sourceforge.net/p/mcomix/git/ci/486f02eef164df451a72598ce5989a1b37b49c60/

--- mcomix/run.py.orig	2016-02-12 18:52:12.000000000 +0000
+++ mcomix/run.py
@@ -203,7 +203,11 @@ def run():
 
     try:
         import PIL.Image
-        assert PIL.Image.VERSION >= '1.1.5'
+        try:
+            assert PIL.Image.VERSION >= '1.1.5'
+        except AttributeError:
+            # Field VERSION deprecated in Pillow 5.2.0 and dropped in 6.0.0
+            assert PIL.__version__ >= '5.2.0'
 
     except AssertionError:
         log.error( _("You don't have the required version of the Python Imaging"), end=' ')
