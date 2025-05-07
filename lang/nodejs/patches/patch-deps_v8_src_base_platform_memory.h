$NetBSD: patch-deps_v8_src_base_platform_memory.h,v 1.3 2025/05/07 05:56:48 adam Exp $

Fix build on NetBSD.

--- deps/v8/src/base/platform/memory.h.orig	2025-05-06 12:36:30.000000000 +0000
+++ deps/v8/src/base/platform/memory.h
@@ -27,7 +27,7 @@
 #include <malloc.h>
 #endif
 
-#if (V8_OS_POSIX && !V8_OS_AIX && !V8_OS_SOLARIS && !V8_OS_ZOS && !V8_OS_OPENBSD) || V8_OS_WIN
+#if (V8_OS_POSIX && !V8_OS_AIX && !V8_OS_SOLARIS && !V8_OS_ZOS && !V8_OS_OPENBSD && !V8_OS_NETBSD) || V8_OS_WIN
 #define V8_HAS_MALLOC_USABLE_SIZE 1
 #endif
 
