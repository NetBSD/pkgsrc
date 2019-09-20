$NetBSD: patch-tortoisehg_util_hgversion.py,v 1.1 2019/09/20 10:55:55 nros Exp $
* make tortosiehg run with mercurial 5.1
--- tortoisehg/util/hgversion.py.orig	2019-09-19 21:06:02.537267989 +0000
+++ tortoisehg/util/hgversion.py
@@ -16,7 +16,7 @@ except AttributeError:
     from mercurial import version
     hgversion = version.get_version()
 
-testedwith = '4.9 5.0'
+testedwith = '4.9 5.0 5.1'
 
 def checkhgversion(v):
     """range check the Mercurial version"""
