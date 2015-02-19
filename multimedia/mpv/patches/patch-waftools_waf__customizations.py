$NetBSD: patch-waftools_waf__customizations.py,v 1.3 2015/02/19 08:59:57 wiz Exp $

Fix build with waf-1.8.6 via
https://github.com/mpv-player/mpv/commit/14b231119d2c125bcdcba48d159a78097152e387#diff-d7a74afa06a68dd21074ca4ab9ff0478

--- waftools/waf_customizations.py.orig	2015-01-27 01:23:08.000000000 +0000
+++ waftools/waf_customizations.py
@@ -33,7 +33,13 @@ def build(ctx):
 
     cls = Task.classes['cprogram']
     class cprogram(cls):
-        run_str = cls.hcode + '${LAST_LINKFLAGS}'
+        try:
+            run_str = cls.orig_run_str + '${LAST_LINKFLAGS}'
+        except AttributeError:
+            try:
+                run_str = cls.hcode + '${LAST_LINKFLAGS}'
+            except TypeError:
+                run_str = cls.hcode.decode('iso8859-1') + '${LAST_LINKFLAGS}'
 
     cls = Task.classes['macplist']
     class macplist(cls):
