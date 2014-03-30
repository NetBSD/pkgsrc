$NetBSD: patch-src_framework_mlt__property.h,v 1.2 2014/03/30 19:42:53 abs Exp $

Add conditional section for __NetBSD__

--- src/framework/mlt_property.h.orig	2013-06-03 03:34:35.000000000 +0000
+++ src/framework/mlt_property.h
@@ -32,8 +32,10 @@
 #include <sys/param.h>
 #endif
 
+#include <locale.h>
 #if defined(__GLIBC__) || defined(__DARWIN__) || (__FreeBSD_version >= 900506)
 #include <xlocale.h>
+#elif defined(__NetBSD__) && defined(LC_C_LOCALE)
 #else
 typedef void* locale_t;
 #endif
