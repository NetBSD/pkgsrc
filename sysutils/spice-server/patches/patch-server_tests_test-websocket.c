$NetBSD: patch-server_tests_test-websocket.c,v 1.3 2023/11/09 12:15:50 adam Exp $

Provide fallback definitions for MSG_NOSIGNAL (SunOS).

--- server/tests/test-websocket.c.orig	2023-05-12 08:37:06.000000000 +0000
+++ server/tests/test-websocket.c
@@ -42,6 +42,10 @@
 #include "net-utils.h"
 #include "websocket.h"
 
+#if !defined(MSG_NOSIGNAL)
+#define MSG_NOSIGNAL 0
+#endif
+
 /*
 on data arrived on socket:
   try to read data, read again till error, handle error, on EAGAIN polling again
