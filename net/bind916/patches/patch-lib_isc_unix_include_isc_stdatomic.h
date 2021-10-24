$NetBSD: patch-lib_isc_unix_include_isc_stdatomic.h,v 1.1 2021/10/24 06:40:28 taca Exp $

* Take from NetBSD base.

--- lib/isc/unix/include/isc/stdatomic.h.orig	2021-09-07 09:37:05.000000000 +0000
+++ lib/isc/unix/include/isc/stdatomic.h
@@ -142,7 +142,7 @@ typedef uintmax_t	   atomic_uintmax_t;
 	__c11_atomic_compare_exchange_weak_explicit(obj, expected, desired, \
 						    succ, fail)
 #define atomic_exchange_explicit(obj, desired, order) \
-	__c11_atomic_exchange_explicit(obj, expected, order)
+	__c11_atomic_exchange_explicit(obj, desired, order)
 #elif defined(__GNUC_ATOMICS) /* __atomic builtins */
 #define atomic_init(obj, desired)	 (*obj = desired)
 #define atomic_load_explicit(obj, order) __atomic_load_n(obj, order)
