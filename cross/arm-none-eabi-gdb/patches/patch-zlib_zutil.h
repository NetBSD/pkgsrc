$NetBSD: patch-zlib_zutil.h,v 1.1 2026/10/03 18:25:39 yurix Exp $

Patch the build on macOS.

--- zlib/zutil.h.orig	2026-09-30 10:45:58.123324424 +0000
+++ zlib/zutil.h
@@ -139,15 +139,6 @@ extern z_const char * const z_errmsg[10]
 
 #if defined(MACOS) || defined(TARGET_OS_MAC)
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
