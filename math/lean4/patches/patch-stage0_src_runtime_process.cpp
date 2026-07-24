$NetBSD: patch-stage0_src_runtime_process.cpp,v 1.2 2026/07/24 21:26:20 wiz Exp $

Set proper thread id on NetBSD.
clearenv() does not exist on NetBSD.
https://github.com/leanprover/lean4/pull/14543

--- stage0/src/runtime/process.cpp.orig	2025-07-31 11:25:32.645020915 +0000
+++ stage0/src/runtime/process.cpp
@@ -340,6 +340,8 @@ extern "C" LEAN_EXPORT obj_res lean_io_g
     uint64_t tid;
 #ifdef __APPLE__
     lean_always_assert(pthread_threadid_np(NULL, &tid) == 0);
+#elif defined(__NetBSD__)
+    tid = (uint64_t)pthread_self();
 #elif defined(LEAN_EMSCRIPTEN)
     tid = 0;
 #else
@@ -430,7 +432,7 @@ static optional<pipe> setup_stdio(stdio 
     lean_unreachable();
 }
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__NetBSD__)
 extern "C" char **environ;
 #endif
 
@@ -446,7 +448,7 @@ static obj_res spawn(string_ref const & 
 
     if (pid == 0) {
         if (!inherit_env) {
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__NetBSD__)
             environ = NULL;
 #else
             clearenv();
