$NetBSD: patch-lib_isc_include_isc_types.h,v 1.3 2021/07/20 06:39:45 rin Exp $

Use 32-bit atomic integers for !_LP64 platforms.

--- lib/isc/include/isc/types.h.orig	2021-07-19 01:22:42.547182690 +0900
+++ lib/isc/include/isc/types.h	2021-07-19 01:22:47.029721976 +0900
@@ -83,7 +83,7 @@ typedef struct isc_socket      isc_socke
 typedef struct isc_socketevent isc_socketevent_t;     /*%< Socket Event */
 typedef struct isc_socketmgr   isc_socketmgr_t;	      /*%< Socket Manager */
 typedef struct isc_stats       isc_stats_t;	      /*%< Statistics */
-#if defined(_WIN32) && !defined(_WIN64)
+#if (defined(_WIN32) && !defined(_WIN64)) || !defined(_LP64)
 typedef int_fast32_t isc_statscounter_t; /*%< Statistics Counter */
 #else  /* if defined(_WIN32) && !defined(_WIN64) */
 typedef int_fast64_t isc_statscounter_t;
