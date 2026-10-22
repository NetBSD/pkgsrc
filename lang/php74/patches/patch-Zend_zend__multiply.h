$NetBSD: patch-Zend_zend__multiply.h,v 1.1 2026/10/22 02:06:45 taca Exp $

Fix for CVE-2026-109618-109619.

--- Zend/zend_multiply.h.orig	2022-10-31 10:36:16.000000000 +0000
+++ Zend/zend_multiply.h
@@ -321,7 +321,7 @@ static zend_always_inline size_t zend_sa
 	size_t ret = zend_safe_address(nmemb, size, offset, &overflow);
 
 	if (UNEXPECTED(overflow)) {
-		zend_error_noreturn(E_ERROR, "Possible integer overflow in memory allocation (%zu * %zu + %zu)", nmemb, size, offset);
+		zend_mm_safe_error_ex("Possible integer overflow in memory allocation (%zu * %zu + %zu)", nmemb, size, offset);
 		return 0;
 	}
 	return ret;
@@ -334,7 +334,7 @@ static zend_always_inline size_t zend_sa
 	size_t ret = zend_safe_address(nmemb, size, offset, &overflow);
 
 	if (UNEXPECTED(overflow)) {
-		zend_error_noreturn(E_ERROR, "Possible integer overflow in %s (%zu * %zu + %zu)", message, nmemb, size, offset);
+		zend_mm_safe_error_ex("Possible integer overflow in %s (%zu * %zu + %zu)", message, nmemb, size, offset);
 		return 0;
 	}
 	return ret;
