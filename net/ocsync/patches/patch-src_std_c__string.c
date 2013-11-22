$NetBSD: patch-src_std_c__string.c,v 1.1 2013/11/22 12:01:13 ryoon Exp $

* For NetBSD iconv(3), this should be fixed for GNU iconv and NetBSD case.

--- src/std/c_string.c.orig	2013-10-18 13:11:09.000000000 +0000
+++ src/std/c_string.c
@@ -83,7 +83,11 @@ enum iconv_direction { iconv_from_native
 
 static char *c_iconv(const char* str, enum iconv_direction dir)
 {
+#if !defined(__NetBSD__)
   char *in = (char*)str;
+#else
+  const char *in = (char*)str;
+#endif
   size_t size;
   size_t outsize;
   char *out;
