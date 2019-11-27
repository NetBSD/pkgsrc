$NetBSD: patch-festival_src_modules_hts__engine_HTS__misc.c,v 1.2 2019/11/27 14:44:05 nia Exp $

Support NetBSD and FreeBSD.

--- festival/src/modules/hts_engine/HTS_misc.c.orig	2017-09-04 15:54:08.000000000 +0000
+++ festival/src/modules/hts_engine/HTS_misc.c
@@ -245,8 +245,10 @@ size_t HTS_ftell(HTS_File * fp)
    } else if (fp->type == HTS_FILE) {
       fpos_t pos;
       fgetpos((FILE *) fp->pointer, &pos);
-#if defined(_WIN32) || defined(__CYGWIN__) || defined(__APPLE__)
+#if defined(_WIN32) || defined(__CYGWIN__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__sun)
       return (size_t) pos;
+#elif defined(__NetBSD__)
+      return (size_t) pos._pos;
 #else
       return (size_t) pos.__pos;
 #endif                          /* _WIN32 || __APPLE__ */
