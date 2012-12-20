$NetBSD: patch-e2fsprogs-1.41.9_ext2fs_bitops.h,v 1.1 2012/12/20 21:54:24 joerg Exp $

--- e2fsprogs-1.41.9/ext2fs/bitops.h.orig	2009-10-19 13:17:52.000000000 +0000
+++ e2fsprogs-1.41.9/ext2fs/bitops.h
@@ -139,7 +139,7 @@ extern __u32 ext2fs_get_generic_bitmap_e
 #define _INLINE_ extern
 #else
 #ifdef __GNUC__
-#define _INLINE_ extern __inline__
+#define _INLINE_ extern __attribute__((__gnu_inline__)) __inline__
 #else				/* For Watcom C */
 #define _INLINE_ extern inline
 #endif
