$NetBSD: patch-src_framework_mlt__property.h,v 1.1 2013/06/26 21:59:10 joerg Exp $

--- src/framework/mlt_property.h.orig	2013-06-26 21:36:42.000000000 +0000
+++ src/framework/mlt_property.h
@@ -31,8 +31,10 @@
 #include <sys/param.h>
 #endif
 
+#include <locale.h>
 #if defined(__GLIBC__) || defined(__DARWIN__) || (__FreeBSD_version >= 900506)
 #include <xlocale.h>
+#elif defined(__NetBSD__) && defined(LC_C_LOCALE)
 #else
 typedef void* locale_t;
 #endif
