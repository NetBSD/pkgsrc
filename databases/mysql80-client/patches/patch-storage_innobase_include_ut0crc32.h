$NetBSD: patch-storage_innobase_include_ut0crc32.h,v 1.1 2024/12/24 18:52:22 adam Exp $

BSD platforms should behave like Darwin.

--- storage/innobase/include/ut0crc32.h.orig	2024-12-24 10:54:43.926389541 +0000
+++ storage/innobase/include/ut0crc32.h
@@ -59,7 +59,7 @@ this program; if not, write to the Free 
 #endif /* _WIN32 */
 #elif defined(__aarch64__) && defined(__GNUC__)
 #define CRC32_ARM64
-#ifdef APPLE_ARM
+#if defined(APPLE_ARM) || !defined(__linux__)
 #define CRC32_ARM64_APPLE
 #else /* APPLE_ARM */
 #define CRC32_ARM64_DEFAULT
