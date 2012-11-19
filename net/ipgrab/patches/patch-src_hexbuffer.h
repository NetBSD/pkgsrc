$NetBSD: patch-src_hexbuffer.h,v 1.1 2012/11/19 03:06:04 joerg Exp $

--- src/hexbuffer.h.orig	2012-11-19 00:55:40.000000000 +0000
+++ src/hexbuffer.h
@@ -32,7 +32,7 @@
 #include "global.h"
 #include "local.h"
 
-inline void hexbuffer_add(u_int8_t *ptr, int length);
-inline void hexbuffer_flush(void);
-inline void hexbuffer_kill(void);
+void hexbuffer_add(u_int8_t *ptr, int length);
+void hexbuffer_flush(void);
+void hexbuffer_kill(void);
 #endif
