$NetBSD: patch-src_collect-io.cc,v 1.1 2024/09/30 14:22:28 wiz Exp $

Fix build on NetBSD.
https://github.com/BestImageViewer/geeqie/pull/1526

--- src/collect-io.cc.orig	2024-09-30 14:18:15.183425605 +0000
+++ src/collect-io.cc
@@ -51,6 +51,10 @@
 
 #define GQ_COLLECTION_MARKER "#" GQ_APPNAME
 
+#ifdef __NetBSD__
+#define statfs statvfs
+#endif
+
 enum {
 	GQ_COLLECTION_FAIL_MIN =     300,
 	GQ_COLLECTION_FAIL_PERCENT = 98,
