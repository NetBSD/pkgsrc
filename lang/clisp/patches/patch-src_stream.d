$NetBSD: patch-src_stream.d,v 1.1 2016/01/26 09:13:26 dbj Exp $

--- src/stream.d.orig	2010-07-06 14:21:51.000000000 +0000
+++ src/stream.d
@@ -3994,7 +3994,7 @@ global object iconv_range (object encodi
 nonreturning_function(extern, error_unencodable, (object encoding, chart ch));
 
 /* Avoid annoying warning caused by a wrongly standardized iconv() prototype. */
-#ifdef GNU_LIBICONV
+#if defined(GNU_LIBICONV) && !defined(__APPLE__)
   #undef iconv
   #define iconv(cd,inbuf,inbytesleft,outbuf,outbytesleft) \
     libiconv(cd,(ICONV_CONST char **)(inbuf),inbytesleft,outbuf,outbytesleft)
