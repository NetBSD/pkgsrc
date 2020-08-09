$NetBSD: patch-lib_isc_include_isc_types.h,v 1.1 2020/08/09 15:20:22 taca Exp $

* Take from NetBSD base.

--- lib/isc/include/isc/types.h.orig	2020-05-06 09:59:35.000000000 +0000
+++ lib/isc/include/isc/types.h
@@ -84,7 +84,7 @@ typedef struct isc_socket      isc_socke
 typedef struct isc_socketevent isc_socketevent_t;    /*%< Socket Event */
 typedef struct isc_socketmgr   isc_socketmgr_t;	     /*%< Socket Manager */
 typedef struct isc_stats       isc_stats_t;	     /*%< Statistics */
-#if defined(_WIN32) && !defined(_WIN64)
+#if defined(_WIN32) && !defined(_WIN64) || !defined(_LP64)
 typedef int_fast32_t isc_statscounter_t; /*%< Statistics Counter */
 #else  /* if defined(_WIN32) && !defined(_WIN64) */
 typedef int_fast64_t isc_statscounter_t;
