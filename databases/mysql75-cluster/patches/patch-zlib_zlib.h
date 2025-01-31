$NetBSD: patch-zlib_zlib.h,v 1.1 2025/01/31 14:08:16 wiz Exp $

--- zlib/zlib.h.orig	2025-01-31 13:51:01.281880713 +0000
+++ zlib/zlib.h
@@ -1465,7 +1465,7 @@ ZEXTERN z_size_t ZEXPORT gzfwrite OF((vo
    is returned, and the error state is set to Z_STREAM_ERROR.
 */
 
-ZEXTERN int ZEXPORTVA gzprintf Z_ARG((gzFile file, const char *format, ...));
+ZEXTERN int ZEXPORTVA gzprintf (gzFile file, const char *format, ...);
 /*
      Converts, formats, and writes the arguments to the compressed file under
    control of the format string, as in fprintf.  gzprintf returns the number of
@@ -1899,9 +1899,9 @@ ZEXTERN gzFile         ZEXPORT gzopen_w 
 #endif
 #if defined(STDC) || defined(Z_HAVE_STDARG_H)
 #  ifndef Z_SOLO
-ZEXTERN int            ZEXPORTVA gzvprintf Z_ARG((gzFile file,
+ZEXTERN int            ZEXPORTVA gzvprintf (gzFile file,
                                                   const char *format,
-                                                  va_list va));
+                                                  va_list va);
 #  endif
 #endif
 
