$NetBSD: patch-shlr_sdb_include_sdb_cwisstable.h,v 1.1 2025/03/24 09:55:40 nia Exp $

Use built-in bswap64 on NetBSD.

--- shlr/sdb/include/sdb/cwisstable.h.orig	2025-03-24 09:42:08.245685371 +0000
+++ shlr/sdb/include/sdb/cwisstable.h
@@ -41,6 +41,9 @@
 #if !CWISS_IS_MACPPC
 #include <stdalign.h>
 #endif
+#ifdef __NetBSD__
+#include <sys/types.h>
+#endif
 #include <stdbool.h>
 #include <stddef.h>
 #include <stdint.h>
@@ -890,7 +893,7 @@ typedef uint64_t CWISS_Group;
 
 #if CWISS_HAVE_CLANG_BUILTIN(__builtin_bswap64)
 # define bswap64 __builtin_bswap64
-#else
+#elif !defined(__NetBSD__)
 static inline uint64_t bswap64(uint64_t v) {
 	return ((v & ((uint64_t)0xff << (7 * 8))) >> (7 * 8)) |
 		((v & ((uint64_t)0xff << (6 * 8))) >> (5 * 8)) |
