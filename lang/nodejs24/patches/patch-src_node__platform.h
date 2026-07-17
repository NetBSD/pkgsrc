$NetBSD: patch-src_node__platform.h,v 1.1 2026/07/17 20:50:28 wiz Exp $

https://github.com/nodejs/node/pull/64283

--- src/node_platform.h.orig	2026-06-23 21:45:00.000000000 +0000
+++ src/node_platform.h
@@ -266,6 +266,7 @@ class NodePlatform : public MultiIsolatePlatform {
  private:
   IsolatePlatformDelegate* ForIsolate(v8::Isolate* isolate);
   std::shared_ptr<PerIsolatePlatformData> ForNodeIsolate(v8::Isolate* isolate);
+  bool FlushForegroundTasksForAllIsolates();
 
   Mutex per_isolate_mutex_;
   using DelegatePair = std::pair<IsolatePlatformDelegate*,
