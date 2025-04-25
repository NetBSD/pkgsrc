$NetBSD: patch-libgfortran_io_io.h,v 1.1 2025/04/25 19:35:10 dkazankov Exp $

Don't declare old_locale* an internal_proto to avoid linking problems

--- libgfortran/io/io.h.orig	2024-05-07 09:51:41.000000000 +0300
+++ libgfortran/io/io.h	2024-07-19 01:19:41.778933588 +0300
@@ -65,11 +65,8 @@
 internal_proto(c_locale);
 #else
 extern char* old_locale;
-internal_proto(old_locale);
 extern int old_locale_ctr;
-internal_proto(old_locale_ctr);
 extern __gthread_mutex_t old_locale_lock;
-internal_proto(old_locale_lock);
 #endif
 
 
