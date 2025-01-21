$NetBSD: patch-lib_ext2fs_ext2fs.h,v 1.3 2025/01/21 18:13:57 triaxx Exp $

Force GNU inline semantic.

--- lib/ext2fs/ext2fs.h.orig	2014-08-03 05:26:22.000000000 +0900
+++ lib/ext2fs/ext2fs.h	2014-12-10 21:03:40.000000000 +0900
@@ -1983,7 +1983,7 @@ extern __u64 ext2fs_div64_ceil(__u64 a, 
 #define _INLINE_ inline
 #else
 #ifdef __GNUC__
-#define _INLINE_ extern __inline__
+#define _INLINE_ extern __attribute__((__gnu_inline__)) __inline__
 #else				/* For Watcom C */
 #define _INLINE_ extern inline
 #endif /* __GNUC__ */
