$NetBSD: patch-setup.py,v 1.1 2018/09/05 08:01:13 adam Exp $

Maintain consistant EGG_INFODIR across Python versions.

--- setup.py.orig	2018-09-05 07:51:34.000000000 +0000
+++ setup.py
@@ -28,7 +28,6 @@ rmtree(meta['name']+'.egg-info', ignore_
 
 # Bootstrap
 if not isdir('.git'):
-    setup(version='0', **meta)
     working_set.add_entry('.')
 
 setup(use_scm_version=True, **meta)
