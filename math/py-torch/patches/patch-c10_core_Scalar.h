$NetBSD: patch-c10_core_Scalar.h,v 1.1 2025/01/21 13:36:49 ryoon Exp $

* For long long int of NetBSD.
  Fix "error: call of overloaded 'Scalar(long long int)' is ambiguous"

--- c10/core/Scalar.h.orig	2025-01-18 03:03:27.153131286 +0000
+++ c10/core/Scalar.h
@@ -75,7 +75,7 @@ class C10_API Scalar {
       "int64_t is the same as long long on Windows");
   Scalar(long vv) : Scalar(vv, true) {}
 #endif
-#if defined(__linux__) && !defined(__ANDROID__)
+#if (defined(__linux__) && !defined(__ANDROID__)) || defined(__NetBSD__)
   static_assert(
       std::is_same_v<long, int64_t>,
       "int64_t is the same as long on Linux");
