$NetBSD: patch-src_framework_mlt__property.h,v 1.3 2019/11/27 21:32:09 markd Exp $

Add conditional section for __NetBSD__

--- src/framework/mlt_property.h.orig	2019-11-12 14:44:42.000000000 +1300
+++ src/framework/mlt_property.h
@@ -37,6 +37,7 @@
 #elif defined(__OpenBSD__)
 /* XXX matches __nop_locale glue in libc++ */
 typedef void* locale_t;
+#elif defined(__NetBSD__) && defined(LC_C_LOCALE)
 #else
 typedef char* locale_t;
 #endif
