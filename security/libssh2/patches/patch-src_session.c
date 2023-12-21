$NetBSD: patch-src_session.c,v 1.1 2023/12/21 07:04:19 wiz Exp $

Terrapin fix
https://github.com/libssh2/libssh2/commit/d34d9258b8420b19ec3f97b4cc5bf7aa7d98e35a

--- src/session.c.orig	2023-05-04 06:32:38.000000000 +0000
+++ src/session.c
@@ -464,6 +464,8 @@ libssh2_session_init_ex(LIBSSH2_ALLOC_FU
         session->abstract = abstract;
         session->api_timeout = 0; /* timeout-free API by default */
         session->api_block_mode = 1; /* blocking API by default */
+        session->state = LIBSSH2_STATE_INITIAL_KEX;
+        session->fullpacket_required_type = 0;
         session->packet_read_timeout = LIBSSH2_DEFAULT_READ_TIMEOUT;
         session->flag.quote_paths = 1; /* default behavior is to quote paths
                                           for the scp subsystem */
@@ -1186,6 +1188,7 @@ libssh2_session_disconnect_ex(LIBSSH2_SE
                               const char *desc, const char *lang)
 {
     int rc;
+    session->state &= ~LIBSSH2_STATE_INITIAL_KEX;
     session->state &= ~LIBSSH2_STATE_EXCHANGING_KEYS;
     BLOCK_ADJUST(rc, session,
                  session_disconnect(session, reason, desc, lang));
