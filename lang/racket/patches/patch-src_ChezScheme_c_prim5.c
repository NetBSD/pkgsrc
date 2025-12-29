$NetBSD: patch-src_ChezScheme_c_prim5.c,v 1.1 2025/12/29 01:55:27 ktnb Exp $

Avoid mismatched pointer error on NetBSD

--- src/ChezScheme/c/prim5.c.orig	2025-10-20 23:35:47.000000000 +0000
+++ src/ChezScheme/c/prim5.c
@@ -2340,7 +2340,11 @@ static ptr s_iconv_from_string(uptr cd, 
     under Windows, the iconv dll might have been linked against a different C runtime
     and might therefore set a different errno */
   errno = 0;
+#ifdef __NetBSD__
+  ICONV_FROM((iconv_t)cd, &inbuf, &inbytesleft, &outbuf, &outbytesleft);
+#else
   ICONV_FROM((iconv_t)cd, (ICONV_INBUF_TYPE)&inbuf, &inbytesleft, &outbuf, &outbytesleft);
+#endif
 
   new_i = i + inmax - inbytesleft / sizeof(string_char);
   new_o = oend - outbytesleft;
@@ -2372,7 +2376,12 @@ static ptr s_iconv_to_string(uptr cd, pt
 
  /* see the comment about the iconv return value and errno in s_iconv_from_string */
   errno = 0;
+
+#ifdef __NetBSD__
+  ICONV((iconv_t)cd, &inbuf, &inbytesleft, &outbuf, &outbytesleft);
+#else
   ICONV((iconv_t)cd, (ICONV_INBUF_TYPE)&inbuf, &inbytesleft, &outbuf, &outbytesleft);
+#endif
 
   outmax -= outbytesleft / sizeof(string_char);
   for (k = 0; k < outmax; k += 1) Sstring_set(out, o + k, buf[k]);
