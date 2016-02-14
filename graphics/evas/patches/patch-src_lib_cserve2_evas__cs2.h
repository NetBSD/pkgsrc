$NetBSD: patch-src_lib_cserve2_evas__cs2.h,v 1.1 2016/02/14 13:14:06 jperkin Exp $

Support systems which don't define MSG_NOSIGNAL.

--- src/lib/cserve2/evas_cs2.h.orig	2012-11-23 16:35:06.000000000 +0000
+++ src/lib/cserve2/evas_cs2.h
@@ -3,6 +3,10 @@
 
 #include <Eina.h>
 
+#ifndef MSG_NOSIGNAL
+#define MSG_NOSIGNAL	0
+#endif
+
 #ifdef EVAS_CSERVE2
 
 typedef enum {
