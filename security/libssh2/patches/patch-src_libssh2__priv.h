$NetBSD: patch-src_libssh2__priv.h,v 1.1 2023/12/21 07:04:19 wiz Exp $

Terrapin fix
https://github.com/libssh2/libssh2/commit/d34d9258b8420b19ec3f97b4cc5bf7aa7d98e35a

--- src/libssh2_priv.h.orig	2023-05-04 06:32:38.000000000 +0000
+++ src/libssh2_priv.h
@@ -699,6 +699,9 @@ struct _LIBSSH2_SESSION
     /* key signing algorithm preferences -- NULL yields server order */
     char *sign_algo_prefs;
 
+    /* Whether to use the OpenSSH Strict KEX extension */
+    int kex_strict;
+
     /* (remote as source of data -- packet_read ) */
     libssh2_endpoint_data remote;
 
@@ -870,6 +873,7 @@ struct _LIBSSH2_SESSION
     int fullpacket_macstate;
     size_t fullpacket_payload_len;
     int fullpacket_packet_type;
+    uint32_t fullpacket_required_type;
 
     /* State variables used in libssh2_sftp_init() */
     libssh2_nonblocking_states sftpInit_state;
@@ -910,10 +914,11 @@ struct _LIBSSH2_SESSION
 };
 
 /* session.state bits */
-#define LIBSSH2_STATE_EXCHANGING_KEYS   0x00000001
-#define LIBSSH2_STATE_NEWKEYS           0x00000002
-#define LIBSSH2_STATE_AUTHENTICATED     0x00000004
-#define LIBSSH2_STATE_KEX_ACTIVE        0x00000008
+#define LIBSSH2_STATE_INITIAL_KEX       0x00000001
+#define LIBSSH2_STATE_EXCHANGING_KEYS   0x00000002
+#define LIBSSH2_STATE_NEWKEYS           0x00000004
+#define LIBSSH2_STATE_AUTHENTICATED     0x00000008
+#define LIBSSH2_STATE_KEX_ACTIVE        0x00000010
 
 /* session.flag helpers */
 #ifdef MSG_NOSIGNAL
@@ -1144,6 +1149,11 @@ ssize_t _libssh2_send(libssh2_socket_t s
 int _libssh2_kex_exchange(LIBSSH2_SESSION * session, int reexchange,
                           key_exchange_state_t * state);
 
+unsigned char *_libssh2_kex_agree_instr(unsigned char *haystack,
+                                        size_t haystack_len,
+                                        const unsigned char *needle,
+                                        size_t needle_len);
+
 /* Let crypt.c/hostkey.c expose their method structs */
 const LIBSSH2_CRYPT_METHOD **libssh2_crypt_methods(void);
 const LIBSSH2_HOSTKEY_METHOD **libssh2_hostkey_methods(void);
