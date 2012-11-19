$NetBSD: patch-lib_ext2fs_bitops.h,v 1.1 2012/11/19 03:02:14 joerg Exp $

--- lib/ext2fs/bitops.h.orig	2012-11-19 02:21:39.000000000 +0000
+++ lib/ext2fs/bitops.h
@@ -135,7 +135,7 @@ extern __u32 ext2fs_get_generic_bitmap_e
 #define _INLINE_ extern
 #else
 #ifdef __GNUC__
-#define _INLINE_ extern __inline__
+#define _INLINE_ extern __attribute__((__gnu_inline__)) __inline__
 #else				/* For Watcom C */
 #define _INLINE_ extern inline
 #endif
