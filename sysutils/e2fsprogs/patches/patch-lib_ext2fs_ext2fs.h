$NetBSD: patch-lib_ext2fs_ext2fs.h,v 1.2 2016/08/09 21:46:07 jdolecek Exp $

Force GNU inline semantic.

--- lib/ext2fs/ext2fs.h.orig	2014-08-03 05:26:22.000000000 +0900
+++ lib/ext2fs/ext2fs.h	2014-12-10 21:03:40.000000000 +0900
@@ -1529,7 +1529,7 @@ extern __u64 ext2fs_div64_ceil(__u64 a, 
 #define _INLINE_ inline
 #else
 #ifdef __GNUC__
-#define _INLINE_ extern __inline__
+#define _INLINE_ extern __attribute__((__gnu_inline__)) __inline__
 #else				/* For Watcom C */
 #define _INLINE_ extern inline
 #endif /* __GNUC__ */
