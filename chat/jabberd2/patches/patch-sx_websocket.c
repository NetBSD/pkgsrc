$NetBSD: patch-sx_websocket.c,v 1.1 2021/02/06 15:20:15 dbj Exp $

use htons instead of non-portable htobe16

--- sx/websocket.c.orig	2018-04-22 09:41:35.000000000 +0000
+++ sx/websocket.c
@@ -214,7 +214,7 @@ int libwebsock_close_with_reason(sx_t s,
     unsigned short code_be;
     char buf[128]; //w3 spec on WebSockets API (http://dev.w3.org/html5/websockets/) says reason shouldn't be over 123 bytes.  I concur.
     len = 2;
-    code_be = htobe16(code);
+    code_be = htons(code);
     memcpy(buf, &code_be, 2);
     if (reason) {
         len += snprintf(buf + 2, 124, "%s", reason);
@@ -235,7 +235,7 @@ int libwebsock_close(sx_t s, _sx_websock
 void libwebsock_fail_connection(sx_t s, _sx_websocket_conn_t sc, unsigned short close_code) {
     char close_frame[4] = { 0x88, 0x02, 0x00, 0x00 };
     unsigned short *code_be = (unsigned short *) &close_frame[2];
-    *code_be = htobe16(WS_CLOSE_PROTOCOL_ERROR);
+    *code_be = htons(WS_CLOSE_PROTOCOL_ERROR);
 
     sx_buf_t buf = _sx_buffer_new(NULL, sizeof(close_frame), NULL, NULL);
     memcpy(buf->data, close_frame, buf->len);
