$NetBSD: patch-src_runtime_process.cpp,v 1.2 2026/07/24 21:26:20 wiz Exp $

Set proper thread id on NetBSD.
clearenv() does not exist on NetBSD.
https://github.com/leanprover/lean4/pull/14543

--- src/runtime/process.cpp.orig	2026-07-23 16:38:08.850506865 +0000
+++ src/runtime/process.cpp
@@ -341,6 +341,8 @@ extern "C" LEAN_EXPORT uint64_t lean_io_get_tid() {
     uint64_t tid;
 #ifdef __APPLE__
     lean_always_assert(pthread_threadid_np(NULL, &tid) == 0);
+#elif defined(__NetBSD__)
+    tid = (uint64_t)pthread_self();
 #elif defined(LEAN_EMSCRIPTEN)
     tid = 0;
 #else
@@ -431,7 +433,7 @@ static optional<pipe> setup_stdio(stdio cfg) {
     lean_unreachable();
 }
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__NetBSD__)
 extern "C" char **environ;
 #endif
 
@@ -454,7 +456,7 @@ static obj_res spawn(string_ref const & proc_name, arr
 
     if (pid == 0) {
         if (!inherit_env) {
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__NetBSD__)
             environ = NULL;
 #else
             clearenv();
