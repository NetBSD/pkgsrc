$NetBSD: patch-e2fsck_jfs__user.h,v 1.3 2025/01/21 18:13:57 triaxx Exp $

Force GNU inline semantic.

--- e2fsck/jfs_user.h.orig	2014-07-06 13:13:18.000000000 +0900
+++ e2fsck/jfs_user.h	2014-12-10 21:09:03.000000000 +0900
@@ -133,7 +133,7 @@ extern size_t journal_tag_bytes(journal_
 #define _INLINE_ inline
 #else /* not C99 */
 #ifdef __GNUC__
-#define _INLINE_ extern __inline__
+#define _INLINE_ extern __attribute__((__gnu_inline__)) __inline__
 #else				/* For Watcom C */
 #define _INLINE_ extern inline
 #endif /* __GNUC__ */
