$NetBSD: patch-mspack_system.h,v 1.1 2011/02/08 20:15:18 jakllsch Exp $
Autoconf has already assured us of a 64-bit off_t.

--- mspack/system.h.orig	2010-06-17 23:46:06.000000000 +0000
+++ mspack/system.h
@@ -15,6 +15,7 @@
 # include <config.h>
 #endif
 
+#include <inttypes.h>
 #include <mspack.h>
 
 /* fix for problem with GCC 4 and glibc (thanks to Ville Skytta)
@@ -53,17 +54,8 @@
 # include <limits.h>
 #endif
 
-#if ((defined(_FILE_OFFSET_BITS) && _FILE_OFFSET_BITS >= 64) || \
-     (defined(FILESIZEBITS)      && FILESIZEBITS      >= 64) || \
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
