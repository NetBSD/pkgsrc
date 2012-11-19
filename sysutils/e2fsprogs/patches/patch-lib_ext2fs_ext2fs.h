$NetBSD: patch-lib_ext2fs_ext2fs.h,v 1.1 2012/11/19 03:02:14 joerg Exp $

--- lib/ext2fs/ext2fs.h.orig	2012-11-19 02:21:42.000000000 +0000
+++ lib/ext2fs/ext2fs.h
@@ -1180,7 +1180,7 @@ extern unsigned int ext2fs_div_ceil(unsi
 #define _INLINE_ extern
 #else
 #ifdef __GNUC__
-#define _INLINE_ extern __inline__
+#define _INLINE_ extern __attribute__((__gnu_inline__)) __inline__
 #else				/* For Watcom C */
 #define _INLINE_ extern inline
 #endif
