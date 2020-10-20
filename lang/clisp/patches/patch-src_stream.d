$NetBSD: patch-src_stream.d,v 1.2 2020/10/20 12:46:17 jperkin Exp $

Remove incomplete iconv handling, it doesn't work everywhere, and warnings
are far preferable to errors.

--- src/stream.d.orig	2010-07-06 14:21:51.000000000 +0000
+++ src/stream.d
@@ -3993,16 +3993,6 @@ global object iconv_range (object encodi
  error_unencodable(encoding); */
 nonreturning_function(extern, error_unencodable, (object encoding, chart ch));
 
-/* Avoid annoying warning caused by a wrongly standardized iconv() prototype. */
-#ifdef GNU_LIBICONV
-  #undef iconv
-  #define iconv(cd,inbuf,inbytesleft,outbuf,outbytesleft) \
-    libiconv(cd,(ICONV_CONST char **)(inbuf),inbytesleft,outbuf,outbytesleft)
-#else
-  #define iconv(cd,inbuf,inbytesleft,outbuf,outbytesleft) \
-    (iconv)(cd,(ICONV_CONST char **)(inbuf),inbytesleft,outbuf,outbytesleft)
-#endif
-
 /* open the iconv conversion and signal errors when necessary
  skip error when CHARSET is NULLOBJ
  begin_system_call() must be called before this!!!
