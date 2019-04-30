$NetBSD: patch-lib_isc_include_isc_types.h,v 1.1 2019/04/30 03:34:34 taca Exp $

* Changes change from NetBSD base.

--- lib/isc/include/isc/types.h.orig	2019-04-06 20:09:59.000000000 +0000
+++ lib/isc/include/isc/types.h
@@ -65,7 +65,11 @@ typedef struct isc_ratelimiter		isc_rate
 typedef struct isc_region		isc_region_t;		/*%< Region */
 typedef uint64_t			isc_resourcevalue_t;	/*%< Resource Value */
 typedef unsigned int			isc_result_t;		/*%< Result */
+#ifndef ISC_PLATFORM_USE_NATIVE_RWLOCKS
 typedef struct isc_rwlock		isc_rwlock_t;		/*%< Read Write Lock */
+#else
+typedef pthread_rwlock_t		isc_rwlock_t;		/*%< Read Write Lock */
+#endif
 typedef struct isc_sockaddr		isc_sockaddr_t;		/*%< Socket Address */
 typedef ISC_LIST(isc_sockaddr_t)	isc_sockaddrlist_t;	/*%< Socket Address List */
 typedef struct isc_socket		isc_socket_t;		/*%< Socket */
