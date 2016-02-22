$NetBSD: patch-lex.c,v 1.1 2016/02/22 12:53:32 jperkin Exp $

Fix build with Darwin/clang.

--- lex.c.orig	2008-05-31 11:44:49.000000000 +0000
+++ lex.c
@@ -67,6 +67,9 @@ hash (str, len)
 
 #ifdef __GNUC__
 __inline
+#  if defined __GNUC_STDC_INLINE__ || defined __GNUC_GNU_INLINE__
+__attribute__ ((__gnu_inline__))
+#  endif
 #endif
 struct kwtable *
 rb_reserved_word (str, len)
