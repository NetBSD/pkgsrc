$NetBSD: patch-libtc_tcavcodec.h,v 1.1 2012/11/17 21:46:44 markd Exp $

Fix build with ffmpeg 0.11. gentoo patch from Brennan Shacklett

--- libtc/tcavcodec.h.orig	2011-11-19 16:50:27.000000000 +0000
+++ libtc/tcavcodec.h
@@ -53,7 +53,6 @@ extern pthread_mutex_t tc_libavcodec_mut
 
 #define TC_INIT_LIBAVCODEC do { \
     TC_LOCK_LIBAVCODEC; \
-    avcodec_init(); \
     avcodec_register_all(); \
     TC_UNLOCK_LIBAVCODEC; \
 } while (0)
