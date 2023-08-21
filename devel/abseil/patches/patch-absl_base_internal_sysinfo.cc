$NetBSD: patch-absl_base_internal_sysinfo.cc,v 1.1 2023/08/21 14:52:26 adam Exp $

Quick fix for https://github.com/abseil/abseil-cpp/issues/1518

--- absl/base/internal/sysinfo.cc.orig	2023-08-21 14:43:13.000000000 +0000
+++ absl/base/internal/sysinfo.cc
@@ -447,7 +447,7 @@ pid_t GetTID() {
 pid_t GetTID() {
   // `pthread_t` need not be arithmetic per POSIX; platforms where it isn't
   // should be handled above.
-  return static_cast<pid_t>(pthread_self());
+  return static_cast<pid_t>((intptr_t)pthread_self());
 }
 
 #endif
