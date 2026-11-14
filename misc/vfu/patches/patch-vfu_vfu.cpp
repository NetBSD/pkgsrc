$NetBSD: patch-vfu_vfu.cpp,v 1.1 2026/11/14 21:17:47 drixter Exp $

Relay on statvfs instead statfs

--- vfu/vfu.cpp.orig
+++ vfu/vfu.cpp
@@ -1171,2 +1171,2 @@
-  struct statfs stafs;
-  statfs( ".", &stafs );
+  struct statvfs stafs;
+  statvfs( ".", &stafs );
@@ -2533,2 +2533,2 @@
-    struct statfs stafs;
-    statfs( t, &stafs );
+    struct statvfs stafs;
+    statvfs( t, &stafs );
