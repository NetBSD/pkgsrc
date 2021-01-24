$NetBSD: patch-setupext.py,v 1.1 2021/01/24 07:39:36 ryoon Exp $

* libqhull is not provided anymore by math/qhull since 2020.2.
  Use libqhull_r instead.

--- setupext.py.orig	2020-11-12 04:38:07.000000000 +0000
+++ setupext.py
@@ -505,7 +505,7 @@ def add_libagg_flags_and_sources(ext):
 
 def add_qhull_flags(ext):
     if options.get("system_qhull"):
-        ext.libraries.append("qhull")
+        ext.libraries.append("qhull_r")
     else:
         ext.include_dirs.insert(0, "extern")
         ext.sources.extend(sorted(glob.glob("extern/libqhull/*.c")))
