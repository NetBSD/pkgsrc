$NetBSD: patch-libskk_expr.c,v 1.1 2012/11/16 01:02:53 joerg Exp $

--- libskk/expr.c.orig	2012-11-15 12:30:02.000000000 +0000
+++ libskk/expr.c
@@ -495,7 +495,7 @@ void skk_expr_reader_read_string (SkkExp
 #line 62 "/home/ueno/devel/libskk/libskk/expr.vala"
 	_tmp8_ = _tmp0_;
 #line 62 "/home/ueno/devel/libskk/libskk/expr.vala"
-	g_return_val_if_fail (_tmp8_, NULL);
+	g_return_if_fail (_tmp8_);
 #line 64 "/home/ueno/devel/libskk/libskk/expr.vala"
 	_tmp9_ = g_string_new ("");
 #line 64 "/home/ueno/devel/libskk/libskk/expr.vala"
