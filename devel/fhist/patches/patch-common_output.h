$NetBSD: patch-common_output.h,v 1.1 2013/02/26 10:25:38 joerg Exp $

--- common/output.h.orig	2013-02-25 17:15:42.000000000 +0000
+++ common/output.h
@@ -74,7 +74,7 @@ void output_fprintf(output_ty *, const c
 void output_vfprintf(output_ty *, const char *, va_list);
 
 #ifndef DEBUG
-#ifdef __GNUC__
+#if defined(__GNUC__) && !defined(__clang__)
 
 extern __inline const char *output_filename(output_ty *fp) { return
 	fp->vptr->filename(fp); }
