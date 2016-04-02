$NetBSD: patch-ext_standard_php__dns.h,v 1.1 2016/04/02 09:00:25 taca Exp $

Fix memory leak.

--- ext/standard/php_dns.h.orig	2016-03-30 23:35:38.000000000 +0000
+++ ext/standard/php_dns.h
@@ -33,7 +33,7 @@
 #define php_dns_search(res, dname, class, type, answer, anslen) \
 			res_nsearch(res, dname, class, type, answer, anslen);
 #define php_dns_free_handle(res) \
-			res_nclose(res); \
+			res_ndestroy(res); \
 			php_dns_free_res(*res)
 
 #elif defined(HAVE_RES_SEARCH)
