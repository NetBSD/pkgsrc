$NetBSD: patch-qa_qa__utils_error__handlers.cpp,v 1.1 2026/09/29 16:11:57 bouyer Exp $

Add NetBSD support.

--- qa/qa_utils/error_handlers.cpp.orig	2026-05-05 13:14:12.564189526 +0000
+++ qa/qa_utils/error_handlers.cpp
@@ -25,7 +25,7 @@
 #include <string>
 #include <iostream>
 #include <qa_utils/error_handlers.h>
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__)
 #define BOOST_STACKTRACE_GNU_SOURCE_NOT_REQUIRED
 #endif
 #ifdef __linux__
