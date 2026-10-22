$NetBSD: patch-Zend_zend__hash.h,v 1.1 2026/10/22 02:06:45 taca Exp $

Fix for CVE-2026-109618-109619.

--- Zend/zend_hash.h.orig	2022-10-31 10:36:16.000000000 +0000
+++ Zend/zend_hash.h
@@ -296,6 +296,7 @@ ZEND_API int ZEND_FASTCALL zend_hash_reh
 #endif
 
 ZEND_API HashTable* ZEND_FASTCALL _zend_new_array_0(void);
+ZEND_API HashTable* ZEND_FASTCALL zend_new_array_singleton(void);
 ZEND_API HashTable* ZEND_FASTCALL _zend_new_array(uint32_t size);
 ZEND_API HashTable* ZEND_FASTCALL zend_new_pair(zval *val1, zval *val2);
 ZEND_API uint32_t zend_array_count(HashTable *ht);
