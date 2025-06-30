$NetBSD: patch-absl_debugging_stacktrace.cc,v 1.1 2025/06/30 13:04:09 adam Exp $

Fix build on NetBSD.

--- absl/debugging/stacktrace.cc.orig	2025-06-11 13:31:38.698546333 +0000
+++ absl/debugging/stacktrace.cc
@@ -60,7 +60,7 @@
 #if __has_include(<alloca.h>)
 #include <alloca.h>
 #define ABSL_INTERNAL_HAVE_ALLOCA 1
-#elif !defined(alloca)
+#elif !defined(alloca) && !defined(__NetBSD__)
 static void* alloca(size_t) noexcept { return nullptr; }
 #endif
 #endif
