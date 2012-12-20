$NetBSD: patch-e2fsprogs-1.41.9_ext2fs_ext2fs.h,v 1.1 2012/12/20 21:54:24 joerg Exp $

--- e2fsprogs-1.41.9/ext2fs/ext2fs.h.orig	2012-12-20 13:55:15.000000000 +0000
+++ e2fsprogs-1.41.9/ext2fs/ext2fs.h
@@ -1179,7 +1179,7 @@ extern unsigned int ext2fs_div_ceil(unsi
 #define _INLINE_ extern
 #else
 #ifdef __GNUC__
-#define _INLINE_ extern __inline__
+#define _INLINE_ extern __attribute__((__gnu_inline__)) __inline__
 #else				/* For Watcom C */
 #define _INLINE_ extern inline
 #endif
