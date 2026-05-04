$NetBSD: patch-jfbuild_include_compat.h,v 1.1 2026/05/04 12:28:52 nia Exp $

Build on NetBSD.

--- jfbuild/include/compat.h.orig	2025-12-26 07:45:04.000000000 +0000
+++ jfbuild/include/compat.h
@@ -28,6 +28,10 @@
 #define USE_COMPAT_H_BMACROS 1
 #endif
 
+#ifdef __NetBSD__
+#define _NETBSD_SOURCE # dirfd etc
+#endif
+
 #ifndef _XOPEN_SOURCE
 # define _XOPEN_SOURCE 700
 #endif
@@ -120,9 +124,9 @@ typedef unsigned __int64 uint64_t;
 #  define B_LITTLE_ENDIAN 0
 #  define B_BIG_ENDIAN    1
 # endif
-# define B_SWAP64(x) __bswap64(x)
-# define B_SWAP32(x) __bswap32(x)
-# define B_SWAP16(x) __bswap16(x)
+# define B_SWAP64(x) bswap64(x)
+# define B_SWAP32(x) bswap32(x)
+# define B_SWAP16(x) bswap16(x)
 
 #elif defined(__APPLE__)
 # if defined(__LITTLE_ENDIAN__)
