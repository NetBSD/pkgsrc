$NetBSD: patch-mspack_system.h,v 1.2 2011/05/13 04:10:47 adam Exp $

Autoconf has already assured us of a 64-bit off_t.

--- mspack/system.h.orig	2011-04-26 17:15:21.000000000 +0000
+++ mspack/system.h
@@ -19,6 +19,7 @@ extern "C" {
 # include <config.h>
 #endif
 
+#include <inttypes.h>
 #include <mspack.h>
 
 /* fix for problem with GCC 4 and glibc (thanks to Ville Skytta)
@@ -57,18 +58,8 @@ extern "C" {
 # include <limits.h>
 #endif
 
-#if ((defined(_FILE_OFFSET_BITS) && _FILE_OFFSET_BITS >= 64) || \
-     (defined(FILESIZEBITS)      && FILESIZEBITS      >= 64) || \
-     (defined(SIZEOF_OFF_T)      && SIZEOF_OFF_T      >= 8)  || \
-     defined(_LARGEFILE_SOURCE) || defined(_LARGEFILE64_SOURCE))
-# define LARGEFILE_SUPPORT
-# define LD "lld"
-# define LU "llu"
-#else
-extern const char *largefile_msg;
-# define LD "ld"
-# define LU "lu"
-#endif
+#define LARGEFILE_SUPPORT
+#define LD PRId64
 
 /* endian-neutral reading of little-endian data */
 #define __egi32(a,n) ( ((((unsigned char *) a)[n+3]) << 24) | \
