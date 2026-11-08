$NetBSD: patch-openvdb_openvdb_thread_Threading.h,v 1.1 2026/11/08 15:45:06 ryoon Exp $

* Find self

--- openvdb/openvdb/thread/Threading.h.orig	2026-09-12 10:17:12.349974413 +0000
+++ openvdb/openvdb/thread/Threading.h
@@ -23,6 +23,7 @@
 #include <tbb/blocked_range.h>
 #include <tbb/task.h>
 #include <tbb/task_group.h>
+#include <tbb/version.h>
 
 namespace openvdb {
 OPENVDB_USE_VERSION_NAMESPACE
