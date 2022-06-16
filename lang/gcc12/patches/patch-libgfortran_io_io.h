$NetBSD: patch-libgfortran_io_io.h,v 1.1 2022/06/16 15:43:55 adam Exp $

Don't declare old_locale* an internal_proto to avoid linking problems

--- libgfortran/io/io.h.orig	2018-01-07 10:17:52.000000000 +0000
+++ libgfortran/io/io.h
@@ -57,11 +57,8 @@ extern locale_t c_locale;
 internal_proto(c_locale);
 #else
 extern char* old_locale;
-internal_proto(old_locale);
 extern int old_locale_ctr;
-internal_proto(old_locale_ctr);
 extern __gthread_mutex_t old_locale_lock;
-internal_proto(old_locale_lock);
 #endif
 
 
