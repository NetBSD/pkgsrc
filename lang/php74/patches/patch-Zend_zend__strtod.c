$NetBSD: patch-Zend_zend__strtod.c,v 1.1 2026/10/22 02:06:45 taca Exp $

Fix for CVE-2026-109618-109619.

--- Zend/zend_strtod.c.orig	2022-10-31 10:36:16.000000000 +0000
+++ Zend/zend_strtod.c
@@ -603,7 +603,7 @@ Balloc
 		rv = (Bigint *)MALLOC(sizeof(Bigint) + (x-1)*sizeof(ULong));
 		if (!rv) {
 			FREE_DTOA_LOCK(0);
-			zend_error_noreturn(E_ERROR, "Balloc() failed to allocate memory");
+			zend_mm_safe_error_ex("Balloc() failed to allocate memory");
 		}
 #else
 		len = (sizeof(Bigint) + (x-1)*sizeof(ULong) + sizeof(double) - 1)
@@ -616,7 +616,7 @@ Balloc
 			rv = (Bigint*)MALLOC(len*sizeof(double));
 			if (!rv) {
 				FREE_DTOA_LOCK(0);
-				zend_error_noreturn(E_ERROR, "Balloc() failed to allocate memory");
+				zend_mm_safe_error_ex("Balloc() failed to allocate memory");
 			}
 #endif
 		rv->k = k;
