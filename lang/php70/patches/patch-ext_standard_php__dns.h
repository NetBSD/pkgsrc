$NetBSD: patch-ext_standard_php__dns.h,v 1.1.2.1 2016/05/08 14:27:23 bsiegert Exp $

Fix memory leak.

--- ext/standard/php_dns.h.orig	2016-04-28 18:13:00.000000000 +0000
+++ ext/standard/php_dns.h
@@ -32,9 +32,15 @@
 #elif defined(HAVE_RES_NSEARCH)
 #define php_dns_search(res, dname, class, type, answer, anslen) \
 			res_nsearch(res, dname, class, type, answer, anslen);
+#ifdef __GLIBC__
 #define php_dns_free_handle(res) \
-			res_nclose(res); \
+                        res_nclose(res); \
+                        php_dns_free_res(*res)
+#else
+#define php_dns_free_handle(res) \
+			res_ndestroy(res); \
 			php_dns_free_res(res)
+#endif
 
 #elif defined(HAVE_RES_SEARCH)
 #define php_dns_search(res, dname, class, type, answer, anslen) \
