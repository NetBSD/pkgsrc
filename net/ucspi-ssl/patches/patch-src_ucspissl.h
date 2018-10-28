$NetBSD: patch-src_ucspissl.h,v 1.1 2018/10/28 17:10:27 schmonz Exp $

Disable TLSv1.0.

--- src/ucspissl.h.orig	2018-10-11 12:24:52.000000000 +0000
+++ src/ucspissl.h
@@ -15,7 +15,7 @@
 
 #define SSLv2_DISABLE
 #define SSLv3_DISABLE
-// #define TLSv1_DISABLE
+#define TLSv1_DISABLE
 // #define TLSv1.1_DISABLE
 // #define TLSv1.2_DISABLE
 // #define TLSv1.3_DISABLE
