$NetBSD: patch-common_input.h,v 1.1 2013/02/26 10:25:38 joerg Exp $

--- common/input.h.orig	2013-02-25 17:15:19.000000000 +0000
+++ common/input.h
@@ -67,7 +67,7 @@ struct output_ty; /* existence */
 void input_to_output(input_ty *, struct output_ty *);
 struct string_ty *input_one_line(input_ty *);
 
-#ifdef __GNUC__
+#if defined(__GNUC__) && !defined(__clang__)
 extern __inline long input_read(input_ty *fp, void *data, long len)
 	{ if (len <= 0) return 0; if (fp->pushback_len > 0) {
 	fp->pushback_len--; *(char *)data = fp->pushback_buf[
