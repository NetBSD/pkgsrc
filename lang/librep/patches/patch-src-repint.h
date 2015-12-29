$NetBSD: patch-src-repint.h,v 1.2 2015/12/29 23:34:50 dholland Exp $

Patch up gcc inline mess.

--- src/repint.h.orig	2011-08-19 14:37:20.000000000 +0000
+++ src/repint.h
@@ -243,8 +243,10 @@ typedef struct rep_cons_block_struct {
    call when the heap needs to grow. */
 
 #if defined __GNUC__ && defined __OPTIMIZE__
-extern __inline__ repv inline_Fcons (repv x, repv y);
-extern __inline__ repv
+#if !defined(__GNUC_STDC_INLINE__) || !__GNUC_STDC_INLINE__
+extern
+#endif
+__inline__ repv
 inline_Fcons (repv x, repv y)
 {
     rep_cons *c = rep_cons_freelist;
