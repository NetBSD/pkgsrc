$NetBSD: patch-src_libmissing_strlcpy.h,v 1.1 2024/05/18 22:31:06 bacon Exp $

# Use local strlcpy() without collision

--- src/libmissing/strlcpy.h.orig	2024-05-18 22:09:11.468056157 +0000
+++ src/libmissing/strlcpy.h
@@ -3,7 +3,7 @@
 #endif /* HAVE_CONFIG_H */
 
 #if !HAVE_STRLCPY
-size_t strlcpy(char *dst, const char *src, size_t siz);
+size_t __munge_strlcpy(char *dst, const char *src, size_t siz);
 /*
  *  Copy src to string dst of size siz.  At most siz-1 characters
  *    will be copied.  Always NUL terminates (unless siz == 0).
