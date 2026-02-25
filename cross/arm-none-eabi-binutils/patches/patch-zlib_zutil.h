$NetBSD: patch-zlib_zutil.h,v 1.1 2026/02/25 08:27:41 triaxx Exp $

Remove fdopen #defines in zutil.h.
https://github.com/madler/zlib/commit/4bd9a71

--- zlib/zutil.h.orig	2026-02-25 06:00:37.313140454 +0000
+++ zlib/zutil.h
@@ -137,17 +137,8 @@ extern z_const char * const z_errmsg[10]
 #  endif
 #endif
 
-#if defined(MACOS) || defined(TARGET_OS_MAC)
+#if defined(MACOS)
 #  define OS_CODE  7
-#  ifndef Z_SOLO
-#    if defined(__MWERKS__) && __dest_os != __be_os && __dest_os != __win32_os
-#      include <unix.h> /* for fdopen */
-#    else
-#      ifndef fdopen
-#        define fdopen(fd,mode) NULL /* No fdopen() */
-#      endif
-#    endif
-#  endif
 #endif
 
 #ifdef __acorn
