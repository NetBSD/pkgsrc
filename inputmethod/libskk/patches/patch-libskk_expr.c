$NetBSD: patch-libskk_expr.c,v 1.2 2013/01/25 12:07:13 obache Exp $

--- libskk/expr.c.orig	2012-08-27 02:38:28.000000000 +0000
+++ libskk/expr.c
@@ -360,7 +360,7 @@ void skk_expr_reader_read_string (SkkExp
 		_tmp0_ = FALSE;
 	}
 	_tmp8_ = _tmp0_;
-	g_return_val_if_fail (_tmp8_, NULL);
+	g_return_if_fail (_tmp8_);
 	_tmp9_ = g_string_new ("");
 	builder = _tmp9_;
 	_tmp10_ = *index;
