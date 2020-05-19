$NetBSD: patch-Source_cmWorkerPool.cxx,v 1.1 2020/05/19 13:52:10 joerg Exp $

Redo locking and state machine for fence handling and the worker pool.

(1) All CV use must hold the corresponding mutex, otherwise race
conditions happen. This is mandated by the C++ standard.

(2) Introduce a separate CV for the thread waiting for other jobs to
finish before running a fence. This avoids waking up all other workers
blindly. Correctly wake that thread up when the processing of outstanding
jobs is done.

(3) Split the waiting for a fence to become runnable from a fence is
pending. This avoids problems if more than one fence can end up on the
queue. The thread that took a fence off the queue is responsible for
clearing the fence processing flag.

--- Source/cmWorkerPool.cxx.orig	2020-04-28 14:23:06.000000000 +0000
+++ Source/cmWorkerPool.cxx
@@ -469,11 +469,9 @@ void cmWorkerPoolWorker::UVProcessStart(
 
 void cmWorkerPoolWorker::UVProcessFinished()
 {
-  {
-    std::lock_guard<std::mutex> lock(Proc_.Mutex);
-    if (Proc_.ROP && (Proc_.ROP->IsFinished() || !Proc_.ROP->IsStarted())) {
-      Proc_.ROP.reset();
-    }
+  std::lock_guard<std::mutex> lock(Proc_.Mutex);
+  if (Proc_.ROP && (Proc_.ROP->IsFinished() || !Proc_.ROP->IsStarted())) {
+    Proc_.ROP.reset();
   }
   // Notify idling thread
   Proc_.Condition.notify_one();
@@ -532,6 +530,7 @@ public:
   unsigned int JobsProcessing = 0;
   std::deque<cmWorkerPool::JobHandleT> Queue;
   std::condition_variable Condition;
+  std::condition_variable ConditionFence;
   std::vector<std::unique_ptr<cmWorkerPoolWorker>> Workers;
 
   // -- References
@@ -593,19 +592,12 @@ bool cmWorkerPoolInternal::Process()
 
 void cmWorkerPoolInternal::Abort()
 {
-  bool notifyThreads = false;
   // Clear all jobs and set abort flag
-  {
-    std::lock_guard<std::mutex> guard(Mutex);
-    if (Processing && !Aborting) {
-      // Register abort and clear queue
-      Aborting = true;
-      Queue.clear();
-      notifyThreads = true;
-    }
-  }
-  if (notifyThreads) {
-    // Wake threads
+  std::lock_guard<std::mutex> guard(Mutex);
+  if (!Aborting) {
+    // Register abort and clear queue
+    Aborting = true;
+    Queue.clear();
     Condition.notify_all();
   }
 }
@@ -669,7 +661,7 @@ void cmWorkerPoolInternal::Work(unsigned
     if (Aborting) {
       break;
     }
-    // Wait for new jobs
+    // Wait for new jobs on the main CV
     if (Queue.empty()) {
       ++WorkersIdle;
       Condition.wait(uLock);
@@ -677,20 +669,33 @@ void cmWorkerPoolInternal::Work(unsigned
       continue;
     }
 
-    // Check for fence jobs
-    if (FenceProcessing || Queue.front()->IsFence()) {
-      if (JobsProcessing != 0) {
-        Condition.wait(uLock);
-        continue;
-      }
-      // No jobs get processed. Set the fence job processing flag.
-      FenceProcessing = true;
+    // If there is a fence currently active or waiting,
+    // sleep on the main CV and try again.
+    if (FenceProcessing) {
+      Condition.wait(uLock);
+      continue;
     }
 
     // Pop next job from queue
     jobHandle = std::move(Queue.front());
     Queue.pop_front();
 
+    // Check for fence jobs
+    bool raisedFence = false;
+    if (jobHandle->IsFence()) {
+      FenceProcessing = true;
+      raisedFence = true;
+      // Wait on the Fence CV until all pending jobs are done.
+      while (JobsProcessing != 0 && !Aborting)
+        ConditionFence.wait(uLock);
+      // When aborting, explicitly kick all threads alive once more.
+      if (Aborting) {
+        FenceProcessing = false;
+        Condition.notify_all();
+        break;
+      }
+    }
+
     // Unlocked scope for job processing
     ++JobsProcessing;
     {
@@ -701,11 +706,17 @@ void cmWorkerPoolInternal::Work(unsigned
     }
     --JobsProcessing;
 
-    // Was this a fence job?
-    if (FenceProcessing) {
+    // If this was the thread that entered fence processing
+    // originally, notify all idling workers that the fence
+    // is done.
+    if (raisedFence) {
       FenceProcessing = false;
       Condition.notify_all();
     }
+    // If fence processing is still not done, notify the
+    // the fencing worker when all active jobs are done.
+    if (FenceProcessing && JobsProcessing == 0)
+      ConditionFence.notify_all();
   }
 
   // Decrement running workers count
