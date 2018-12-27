$NetBSD: patch-diffoscope_presenters_formats.py,v 1.1 2018/12/27 15:03:53 joerg Exp $

--- diffoscope/presenters/formats.py.orig	2018-12-25 21:54:25.209444143 +0000
+++ diffoscope/presenters/formats.py
@@ -109,5 +109,5 @@ class PresenterManager(object):
         """
 
         return any(
-            x['klass'].supports_visual_diffs for x in self.config.values(),
+            x['klass'].supports_visual_diffs for x in self.config.values()
         )
