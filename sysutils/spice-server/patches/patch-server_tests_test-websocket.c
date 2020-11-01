$NetBSD: patch-server_tests_test-websocket.c,v 1.1 2020/11/01 19:36:37 maya Exp $

Provide a fallback definition for SOL_TCP (for netbsd)

--- server/tests/test-websocket.c.orig	2020-02-27 11:26:12.000000000 +0000
+++ server/tests/test-websocket.c
@@ -200,6 +200,9 @@ handle_client(int new_sock)
     }
 
     int enable = 1;
+#ifndef SOL_TCP
+#define SOL_TCP IPPROTO_TCP
+#endif
     setsockopt(new_sock, SOL_TCP, TCP_NODELAY, (const void *) &enable, sizeof(enable));
 
     // wait header
