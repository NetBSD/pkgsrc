$NetBSD: patch-Zend_zend__API.h,v 1.1 2026/10/22 02:06:45 taca Exp $

Fix for CVE-2026-109618-109619.

--- Zend/zend_API.h.orig	2022-10-31 10:36:16.000000000 +0000
+++ Zend/zend_API.h
@@ -380,6 +380,7 @@ ZEND_API char *zend_get_type_by_const(in
 
 #define array_init(arg)				ZVAL_ARR((arg), zend_new_array(0))
 #define array_init_size(arg, size)	ZVAL_ARR((arg), zend_new_array(size))
+#define array_init_singleton(arg)	ZVAL_ARR((arg), zend_new_array_singleton())
 ZEND_API int object_init(zval *arg);
 ZEND_API int object_init_ex(zval *arg, zend_class_entry *ce);
 ZEND_API int object_and_properties_init(zval *arg, zend_class_entry *ce, HashTable *properties);
