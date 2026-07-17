$NetBSD: patch-src_node__platform.cc,v 1.1 2026/07/17 20:50:28 wiz Exp $

https://github.com/nodejs/node/pull/64283

--- src/node_platform.cc.orig	2026-06-23 21:45:00.000000000 +0000
+++ src/node_platform.cc
@@ -526,6 +526,12 @@ void NodePlatform::Shutdown() {
 void NodePlatform::Shutdown() {
   if (has_shut_down_) return;
   has_shut_down_ = true;
+
+  // V8 background tasks may be parked waiting for foreground GC work before
+  // they can return from the worker thread task.
+  while (FlushForegroundTasksForAllIsolates()) {
+  }
+
   worker_thread_task_runner_->Shutdown();
 
   {
@@ -715,6 +721,25 @@ bool NodePlatform::FlushForegroundTasks(Isolate* isola
   std::shared_ptr<PerIsolatePlatformData> per_isolate = ForNodeIsolate(isolate);
   if (!per_isolate) return false;
   return per_isolate->FlushForegroundTasksInternal();
+}
+
+bool NodePlatform::FlushForegroundTasksForAllIsolates() {
+  std::vector<std::shared_ptr<PerIsolatePlatformData>> per_isolates;
+  {
+    Mutex::ScopedLock lock(per_isolate_mutex_);
+    per_isolates.reserve(per_isolate_.size());
+    for (const auto& entry : per_isolate_) {
+      if (entry.second.second) {
+        per_isolates.push_back(entry.second.second);
+      }
+    }
+  }
+
+  bool did_work = false;
+  for (const auto& per_isolate : per_isolates) {
+    did_work |= per_isolate->FlushForegroundTasksInternal();
+  }
+  return did_work;
 }
 
 std::unique_ptr<v8::JobHandle> NodePlatform::CreateJobImpl(
