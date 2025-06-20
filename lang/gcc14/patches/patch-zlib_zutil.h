$NetBSD: patch-zlib_zutil.h,v 1.1 2025/06/20 07:05:18 adam Exp $

Fix build with Xcode 16.3.
https://www.mail-archive.com/gcc-bugs@gcc.gnu.org/msg860049.html

--- zlib/zutil.h.orig	2025-06-20 06:34:52.537143884 +0000
+++ zlib/zutil.h
@@ -130,7 +130,7 @@ extern z_const char * const z_errmsg[10]
 #  endif
 #endif
 
-#if defined(MACOS) || defined(TARGET_OS_MAC)
+#if defined(MACOS)
 #  define OS_CODE  7
 #  ifndef Z_SOLO
 #    if defined(__MWERKS__) && __dest_os != __be_os && __dest_os != __win32_os
