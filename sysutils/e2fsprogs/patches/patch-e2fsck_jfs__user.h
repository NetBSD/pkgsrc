$NetBSD: patch-e2fsck_jfs__user.h,v 1.1 2012/11/19 03:02:14 joerg Exp $

--- e2fsck/jfs_user.h.orig	2012-11-19 02:21:35.000000000 +0000
+++ e2fsck/jfs_user.h
@@ -83,7 +83,7 @@ extern size_t journal_tag_bytes(journal_
 #define _INLINE_ extern
 #else
 #ifdef __GNUC__
-#define _INLINE_ extern __inline__
+#define _INLINE_ extern __attribute__((__gnu_inline__)) __inline__
 #else				/* For Watcom C */
 #define _INLINE_ extern inline
 #endif
