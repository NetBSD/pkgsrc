$NetBSD: patch-clickhouse_base_platform.h,v 1.1 2026/06/09 15:05:34 adam Exp $

--- clickhouse/base/platform.h.orig	2026-06-08 12:39:05.053746493 +0000
+++ clickhouse/base/platform.h
@@ -9,6 +9,8 @@
 #   define _win32_
 #elif defined(__APPLE__)
 #   define _darwin_
+#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#   define _bsd_
 #endif
 
 #if defined(_win32_) || defined(_win64_)
@@ -20,7 +22,7 @@
 #   define WIN32_LEAN_AND_MEAN 1  // don't include too much header automatically
 #endif
 
-#if defined(_linux_) || defined (_darwin_)
+#if defined(_linux_) || defined (_darwin_) || defined(_bsd_)
 #   define _unix_
 #endif
 
