$NetBSD: patch-bin_vc_hts__engine__API_HTS__misc.c,v 1.1 2016/07/10 12:06:21 mef Exp $

hts_engine_API/HTS_misc.c: In function 'HTS_ftell':
hts_engine_API/HTS_misc.c:251:26: error: 'fpos_t' has no member named '__pos'

--- bin/vc/hts_engine_API/HTS_misc.c~	2015-12-25 15:10:53.000000000 +0900
+++ bin/vc/hts_engine_API/HTS_misc.c	2016-07-10 21:01:30.000000000 +0900
@@ -245,10 +245,14 @@ size_t HTS_ftell(HTS_File * fp)
    } else if (fp->type == HTS_FILE) {
       fpos_t pos;
       fgetpos((FILE *) fp->pointer, &pos);
-#if defined(_WIN32) || defined(__CYGWIN__) || defined(__APPLE__) || defined(__ANDROID__)
+#if defined(_WIN32) || defined(__CYGWIN__) || defined(__APPLE__) || defined(__ANDROID__) 
       return (size_t) pos;
 #else
+#  if defined(__NetBSD__)
+      return (size_t) pos._pos;
+#  else
       return (size_t) pos.__pos;
+#  endif
 #endif                          /* _WIN32 || __CYGWIN__ || __APPLE__ || __ANDROID__ */
    } else if (fp->type == HTS_DATA) {
       HTS_Data *d = (HTS_Data *) fp->pointer;
