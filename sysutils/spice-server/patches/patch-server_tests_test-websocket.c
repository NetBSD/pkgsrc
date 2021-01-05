$NetBSD: patch-server_tests_test-websocket.c,v 1.2 2021/01/05 15:14:39 jperkin Exp $

Provide fallback definitions for MSG_NOSIGNAL (SunOS) and SOL_TCP (NetBSD)

--- server/tests/test-websocket.c.orig	2020-02-27 11:26:12.000000000 +0000
+++ server/tests/test-websocket.c
@@ -42,6 +42,10 @@
 #include "net-utils.h"
 #include "websocket.h"
 
+#if !defined(MSG_NOSIGNAL)
+#define MSG_NOSIGNAL	0
+#endif
+
 /*
 on data arrived on socket:
   try to read data, read again till error, handle error, on EAGAIN polling again
@@ -200,6 +204,9 @@ handle_client(int new_sock)
     }
 
     int enable = 1;
+#ifndef SOL_TCP
+#define SOL_TCP IPPROTO_TCP
+#endif
     setsockopt(new_sock, SOL_TCP, TCP_NODELAY, (const void *) &enable, sizeof(enable));
 
     // wait header
