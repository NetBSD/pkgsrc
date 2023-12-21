$NetBSD: patch-src_transport.c,v 1.1 2023/12/21 07:04:19 wiz Exp $

Terrapin fix
https://github.com/libssh2/libssh2/commit/d34d9258b8420b19ec3f97b4cc5bf7aa7d98e35a

--- src/transport.c.orig	2023-05-22 19:30:17.000000000 +0000
+++ src/transport.c
@@ -187,6 +187,7 @@ fullpacket(LIBSSH2_SESSION * session, in
     struct transportpacket *p = &session->packet;
     int rc;
     int compressed;
+    uint32_t seq = session->remote.seqno;
 
     if(session->fullpacket_state == libssh2_NB_state_idle) {
         session->fullpacket_macstate = LIBSSH2_MAC_CONFIRMED;
@@ -318,7 +319,7 @@ fullpacket(LIBSSH2_SESSION * session, in
     if(session->fullpacket_state == libssh2_NB_state_created) {
         rc = _libssh2_packet_add(session, p->payload,
                                  session->fullpacket_payload_len,
-                                 session->fullpacket_macstate);
+                                 session->fullpacket_macstate, seq);
         if(rc == LIBSSH2_ERROR_EAGAIN)
             return rc;
         if(rc) {
@@ -329,6 +330,11 @@ fullpacket(LIBSSH2_SESSION * session, in
 
     session->fullpacket_state = libssh2_NB_state_idle;
 
+    if(session->kex_strict &&
+        session->fullpacket_packet_type == SSH_MSG_NEWKEYS) {
+        session->remote.seqno = 0;
+    }
+
     return session->fullpacket_packet_type;
 }
 
@@ -1091,6 +1097,10 @@ int _libssh2_transport_send(LIBSSH2_SESS
 
     session->local.seqno++;
 
+    if(session->kex_strict && data[0] == SSH_MSG_NEWKEYS) {
+        session->local.seqno = 0;
+    }
+
     ret = LIBSSH2_SEND(session, p->outbuf, total_length,
                        LIBSSH2_SOCKET_SEND_FLAGS(session));
     if(ret < 0)
