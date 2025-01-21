$NetBSD: patch-c10_macros_Macros.h,v 1.1 2025/01/21 13:36:49 ryoon Exp $

* Avoid undefined reference of __assert_fail().

--- c10/macros/Macros.h.orig	2025-01-17 17:30:50.856258217 +0000
+++ c10/macros/Macros.h
@@ -342,7 +342,7 @@ constexpr uint32_t CUDA_THREADS_PER_BLOC
 // CUDA_KERNEL_ASSERT checks the assertion
 // even when NDEBUG is defined. This is useful for important assertions in CUDA
 // code that would otherwise be suppressed when building Release.
-#if defined(__ANDROID__) || defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__ANDROID__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__)
 // Those platforms do not support assert()
 #define CUDA_KERNEL_ASSERT(cond)
 #define CUDA_KERNEL_ASSERT_MSG(cond, msg)
