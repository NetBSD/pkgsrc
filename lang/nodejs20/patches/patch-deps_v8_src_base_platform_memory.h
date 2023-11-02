$NetBSD: patch-deps_v8_src_base_platform_memory.h,v 1.1 2023/11/02 13:16:54 adam Exp $

Fix build on NetBSD.

--- deps/v8/src/base/platform/memory.h.orig	2022-11-14 11:44:23.528838940 +0000
+++ deps/v8/src/base/platform/memory.h
@@ -23,7 +23,7 @@
 #include <malloc.h>
 #endif  // !V8_OS_DARWIN
 
-#if (V8_OS_POSIX && !V8_OS_AIX && !V8_OS_SOLARIS) || V8_OS_WIN
+#if (V8_OS_POSIX && !V8_OS_AIX && !V8_OS_NETBSD && !V8_OS_SOLARIS) || V8_OS_WIN
 #define V8_HAS_MALLOC_USABLE_SIZE 1
 #endif  // (V8_OS_POSIX && !V8_OS_AIX && !V8_OS_SOLARIS) || V8_OS_WIN
 
