$NetBSD: patch-src_packet.c,v 1.1 2023/12/21 07:04:19 wiz Exp $

Terrapin fix
https://github.com/libssh2/libssh2/commit/d34d9258b8420b19ec3f97b4cc5bf7aa7d98e35a

--- src/packet.c.orig	2023-05-22 19:30:17.000000000 +0000
+++ src/packet.c
@@ -605,14 +605,13 @@ authagent_exit:
  * layer when it has received a packet.
  *
  * The input pointer 'data' is pointing to allocated data that this function
- * is asked to deal with so on failure OR success, it must be freed fine.
- * The only exception is when the return code is LIBSSH2_ERROR_EAGAIN.
+ * will be freed unless return the code is LIBSSH2_ERROR_EAGAIN.
  *
  * This function will always be called with 'datalen' greater than zero.
  */
 int
 _libssh2_packet_add(LIBSSH2_SESSION * session, unsigned char *data,
-                    size_t datalen, int macstate)
+                    size_t datalen, int macstate, uint32_t seq)
 {
     int rc = 0;
     unsigned char *message = NULL;
@@ -657,6 +656,70 @@ _libssh2_packet_add(LIBSSH2_SESSION * se
         break;
     }
 
+    if(session->state & LIBSSH2_STATE_INITIAL_KEX) {
+        if(msg == SSH_MSG_KEXINIT) {
+            if(!session->kex_strict) {
+                if(datalen < 17) {
+                    LIBSSH2_FREE(session, data);
+                    session->packAdd_state = libssh2_NB_state_idle;
+                    return _libssh2_error(session,
+                                          LIBSSH2_ERROR_BUFFER_TOO_SMALL,
+                                          "Data too short extracting kex");
+                }
+                else {
+                    const unsigned char *strict =
+                    (unsigned char *)"kex-strict-s-v00@openssh.com";
+                    struct string_buf buf;
+                    unsigned char *algs = NULL;
+                    size_t algs_len = 0;
+
+                    buf.data = (unsigned char *)data;
+                    buf.dataptr = buf.data;
+                    buf.len = datalen;
+                    buf.dataptr += 17; /* advance past type and cookie */
+
+                    if(_libssh2_get_string(&buf, &algs, &algs_len)) {
+                        LIBSSH2_FREE(session, data);
+                        session->packAdd_state = libssh2_NB_state_idle;
+                        return _libssh2_error(session,
+                                              LIBSSH2_ERROR_BUFFER_TOO_SMALL,
+                                              "Algs too short");
+                    }
+
+                    if(algs_len == 0 ||
+                       _libssh2_kex_agree_instr(algs, algs_len, strict, 28)) {
+                        session->kex_strict = 1;
+                    }
+                }
+            }
+
+            if(session->kex_strict && seq) {
+                LIBSSH2_FREE(session, data);
+                session->socket_state = LIBSSH2_SOCKET_DISCONNECTED;
+                session->packAdd_state = libssh2_NB_state_idle;
+                libssh2_session_disconnect(session, "strict KEX violation: "
+                                           "KEXINIT was not the first packet");
+
+                return _libssh2_error(session, LIBSSH2_ERROR_SOCKET_DISCONNECT,
+                                      "strict KEX violation: "
+                                      "KEXINIT was not the first packet");
+            }
+        }
+
+        if(session->kex_strict && session->fullpacket_required_type &&
+            session->fullpacket_required_type != msg) {
+            LIBSSH2_FREE(session, data);
+            session->socket_state = LIBSSH2_SOCKET_DISCONNECTED;
+            session->packAdd_state = libssh2_NB_state_idle;
+            libssh2_session_disconnect(session, "strict KEX violation: "
+                                       "unexpected packet type");
+
+            return _libssh2_error(session, LIBSSH2_ERROR_SOCKET_DISCONNECT,
+                                  "strict KEX violation: "
+                                  "unexpected packet type");
+        }
+    }
+
     if(session->packAdd_state == libssh2_NB_state_allocated) {
         /* A couple exceptions to the packet adding rule: */
         switch(msg) {
@@ -1341,6 +1404,15 @@ _libssh2_packet_ask(LIBSSH2_SESSION * se
 
             return 0;
         }
+        else if(session->kex_strict &&
+                (session->state & LIBSSH2_STATE_INITIAL_KEX)) {
+            libssh2_session_disconnect(session, "strict KEX violation: "
+                                       "unexpected packet type");
+
+            return _libssh2_error(session, LIBSSH2_ERROR_SOCKET_DISCONNECT,
+                                  "strict KEX violation: "
+                                  "unexpected packet type");
+        }
         packet = _libssh2_list_next(&packet->node);
     }
     return -1;
@@ -1402,7 +1474,10 @@ _libssh2_packet_require(LIBSSH2_SESSION 
     }
 
     while(session->socket_state == LIBSSH2_SOCKET_CONNECTED) {
-        int ret = _libssh2_transport_read(session);
+        int ret;
+        session->fullpacket_required_type = packet_type;
+        ret = _libssh2_transport_read(session);
+        session->fullpacket_required_type = 0;
         if(ret == LIBSSH2_ERROR_EAGAIN)
             return ret;
         else if(ret < 0) {
