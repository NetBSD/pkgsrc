$NetBSD: patch-lib_HTS__misc.c,v 1.1 2020/06/22 00:52:42 ryoon Exp $

* Add NetBSD workaround.

--- lib/HTS_misc.c.orig	2015-12-25 00:12:53.000000000 +0000
+++ lib/HTS_misc.c
@@ -247,6 +247,8 @@ size_t HTS_ftell(HTS_File * fp)
       fgetpos((FILE *) fp->pointer, &pos);
 #if defined(_WIN32) || defined(__CYGWIN__) || defined(__APPLE__) || defined(__ANDROID__)
       return (size_t) pos;
+#elif (__NetBSD__)
+      return (size_t) pos._pos;
 #else
       return (size_t) pos.__pos;
 #endif                          /* _WIN32 || __CYGWIN__ || __APPLE__ || __ANDROID__ */
