$NetBSD: patch-deps_v8_src_base_platform_memory.h,v 1.2 2024/11/13 08:45:17 adam Exp $

Fix build on NetBSD.

--- deps/v8/src/base/platform/memory.h.orig	2024-10-24 12:44:06.000000000 +0000
+++ deps/v8/src/base/platform/memory.h
@@ -25,7 +25,7 @@
 #include <malloc.h>
 #endif
 
-#if (V8_OS_POSIX && !V8_OS_AIX && !V8_OS_SOLARIS && !V8_OS_ZOS) || V8_OS_WIN
+#if (V8_OS_POSIX && !V8_OS_AIX && !V8_OS_SOLARIS && !V8_OS_ZOS && !V8_OS_NETBSD) || V8_OS_WIN
 #define V8_HAS_MALLOC_USABLE_SIZE 1
 #endif
 
