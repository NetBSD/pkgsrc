$NetBSD: patch-absl_base_config.h,v 1.1 2020/03/15 22:25:56 adam Exp $

Add support for NetBSD.

--- absl/base/config.h.orig	2020-03-15 11:32:41.206104135 +0000
+++ absl/base/config.h
@@ -365,6 +365,7 @@ static_assert(ABSL_INTERNAL_INLINE_NAMES
 #ifdef ABSL_HAVE_MMAP
 #error ABSL_HAVE_MMAP cannot be directly set
 #elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) ||   \
+    defined(__NetBSD__) || \
     defined(__ros__) || defined(__native_client__) || defined(__asmjs__) || \
     defined(__wasm__) || defined(__Fuchsia__) || defined(__sun) || \
     defined(__ASYLO__)
@@ -378,6 +379,7 @@ static_assert(ABSL_INTERNAL_INLINE_NAMES
 #ifdef ABSL_HAVE_PTHREAD_GETSCHEDPARAM
 #error ABSL_HAVE_PTHREAD_GETSCHEDPARAM cannot be directly set
 #elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || \
+    defined(__NetBSD__) || \
     defined(__ros__)
 #define ABSL_HAVE_PTHREAD_GETSCHEDPARAM 1
 #endif
