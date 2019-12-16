$NetBSD: patch-src_ucspissl.h,v 1.2 2019/12/16 21:26:43 schmonz Exp $

Disable TLSv1.0.

--- src/ucspissl.h.orig	2019-10-31 21:23:05.000000000 +0000
+++ src/ucspissl.h
@@ -23,7 +23,7 @@
 
 #define SSLv2_DISABLE
 #define SSLv3_DISABLE
-// #define TLSv1_DISABLE
+#define TLSv1_DISABLE
 // #define TLSv1_1_DISABLE
 // #define TLSv1_2_DISABLE
 // #define TLSv1_3_DISABLE
