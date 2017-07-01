$NetBSD: patch-bin_vc_hts__engine__API_HTS__misc.c,v 1.2 2017/07/01 11:01:44 wiedi Exp $

hts_engine_API/HTS_misc.c: In function 'HTS_ftell':
hts_engine_API/HTS_misc.c:251:26: error: 'fpos_t' has no member named '__pos'

--- bin/vc/hts_engine_API/HTS_misc.c.orig	2015-12-25 06:10:53.000000000 +0000
+++ bin/vc/hts_engine_API/HTS_misc.c
@@ -245,11 +245,15 @@ size_t HTS_ftell(HTS_File * fp)
    } else if (fp->type == HTS_FILE) {
       fpos_t pos;
       fgetpos((FILE *) fp->pointer, &pos);
-#if defined(_WIN32) || defined(__CYGWIN__) || defined(__APPLE__) || defined(__ANDROID__)
+#if defined(_WIN32) || defined(__CYGWIN__) || defined(__APPLE__) || defined(__ANDROID__) || defined(__sun)
       return (size_t) pos;
 #else
+#  if defined(__NetBSD__)
+      return (size_t) pos._pos;
+#  else
       return (size_t) pos.__pos;
-#endif                          /* _WIN32 || __CYGWIN__ || __APPLE__ || __ANDROID__ */
+#  endif
+#endif                          /* _WIN32 || __CYGWIN__ || __APPLE__ || __ANDROID__ || __sun */
    } else if (fp->type == HTS_DATA) {
       HTS_Data *d = (HTS_Data *) fp->pointer;
       return d->index;
