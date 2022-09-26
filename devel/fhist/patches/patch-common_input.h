$NetBSD: patch-common_input.h,v 1.2 2022/09/26 10:21:32 nros Exp $

* remove redefinitions of functions since it conflicts with c99

--- common/input.h.orig	2013-02-25 17:15:19.000000000 +0000
+++ common/input.h
@@ -67,7 +67,7 @@ struct output_ty; /* existence */
 void input_to_output(input_ty *, struct output_ty *);
 struct string_ty *input_one_line(input_ty *);
 
-#ifdef __GNUC__
+#if 0
 extern __inline long input_read(input_ty *fp, void *data, long len)
 	{ if (len <= 0) return 0; if (fp->pushback_len > 0) {
 	fp->pushback_len--; *(char *)data = fp->pushback_buf[
