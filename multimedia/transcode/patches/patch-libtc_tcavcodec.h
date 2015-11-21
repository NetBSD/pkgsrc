$NetBSD: patch-libtc_tcavcodec.h,v 1.2 2015/11/21 17:14:26 adam Exp $

Fixes building against FFmpeg version >= 2.0.0 (gentoo patch).

--- libtc/tcavcodec.h.orig	2011-11-19 16:50:27.000000000 +0000
+++ libtc/tcavcodec.h
@@ -53,7 +53,6 @@ extern pthread_mutex_t tc_libavcodec_mut
 
 #define TC_INIT_LIBAVCODEC do { \
     TC_LOCK_LIBAVCODEC; \
-    avcodec_init(); \
     avcodec_register_all(); \
     TC_UNLOCK_LIBAVCODEC; \
 } while (0)
