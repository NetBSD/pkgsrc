$NetBSD: patch-src_malloc__extension.cc,v 1.1 2017/07/05 11:17:17 adam Exp $

Darwin does not support lsan_ignore_object either.

--- src/malloc_extension.cc.orig	2017-07-05 10:35:01.000000000 +0000
+++ src/malloc_extension.cc
@@ -205,7 +205,7 @@ void MallocExtension::MarkThreadTemporar
 
 static MallocExtension* current_instance;
 
-#if (!defined(_WIN32) && !defined(__MINGW32__))
+#if (!defined(_WIN32) && !defined(__MINGW32__) && !defined(__APPLE__))
 // Provide a weak hook for __lsan_ignore_object, so that
 // if leak sanitizer is enabled, we can ignore the current_instance
 // heap allocation.
