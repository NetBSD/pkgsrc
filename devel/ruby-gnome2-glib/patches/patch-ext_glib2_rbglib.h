$NetBSD: patch-ext_glib2_rbglib.h,v 1.1 2018/04/29 15:36:44 tsutsui Exp $

- pull upstream fix for issue #1162

--- ext/glib2/rbglib.h.orig	2018-04-29 15:03:29.000000000 +0000
+++ ext/glib2/rbglib.h
@@ -46,6 +46,10 @@ extern "C" {
 #  endif
 #endif
 
+#ifndef RB_ALLOC
+#  define RB_ALLOC(type) ALLOC(type)
+#endif
+
 #ifndef RB_ALLOC_N
 #  define RB_ALLOC_N(type, n) ALLOC_N(type, n)
 #endif
