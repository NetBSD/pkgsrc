$NetBSD: patch-src_extra_gd_gdhelpers.h,v 1.1.2.2 2015/07/26 19:49:47 tron Exp $

CVE-2007-3472 - Integer overflow in gdImageCreateTrueColor function.

--- src/extra/gd/gdhelpers.h.orig	2001-03-28 09:37:31.000000000 +0000
+++ src/extra/gd/gdhelpers.h
@@ -13,5 +13,7 @@ void *gdCalloc(size_t nmemb, size_t size
 void *gdMalloc(size_t size);
 void *gdRealloc(void *ptr, size_t size);
 
+int overflow2(int a, int b);
+
 #endif /* GDHELPERS_H */
 
