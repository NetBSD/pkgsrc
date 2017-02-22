$NetBSD: patch-include_type__compat.h,v 1.1 2017/02/22 14:48:09 wiz Exp $

--- include/type_compat.h.orig	2016-12-20 14:43:20.000000000 +0000
+++ include/type_compat.h
@@ -29,6 +29,9 @@
 #define ESTRPIPE EPIPE
 #endif
 
+#ifndef __u8
+#define __u8	uint8_t
+#endif
 #ifndef __u16
 #define __u16	uint16_t
 #endif
