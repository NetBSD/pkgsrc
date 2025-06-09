$NetBSD: patch-deps_v8_third__party_zlib_zutil.h,v 1.1 2025/06/09 18:10:13 adam Exp $

Fix build on Darwin.

--- deps/v8/third_party/zlib/zutil.h.orig	2025-04-25 14:06:50.201077912 +0000
+++ deps/v8/third_party/zlib/zutil.h
@@ -154,7 +154,7 @@ extern z_const char * const z_errmsg[10]
 
 #if defined(MACOS) || defined(TARGET_OS_MAC)
 #  define OS_CODE  7
-#  ifndef Z_SOLO
+#  if 0
 #    if defined(__MWERKS__) && __dest_os != __be_os && __dest_os != __win32_os
 #      include <unix.h> /* for fdopen */
 #    else
