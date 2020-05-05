$NetBSD: patch-res_srtp_srtp__compat.h,v 1.1 2020/05/05 17:59:10 adam Exp $

Fix for newer comms/srtp (from asterisk15).

--- res/srtp/srtp_compat.h.orig	2018-09-20 18:48:30.000000000 +0000
+++ res/srtp/srtp_compat.h
@@ -16,6 +16,18 @@
 #define crypto_policy_set_aes_gcm_128_8_auth srtp_crypto_policy_set_aes_gcm_128_8_auth
 #define crypto_policy_set_aes_gcm_256_8_auth srtp_crypto_policy_set_aes_gcm_256_8_auth
 
+#if defined(SRTP_AES_GCM_128_KEY_LEN_WSALT)
+#define AES_128_GCM_KEYSIZE_WSALT SRTP_AES_GCM_128_KEY_LEN_WSALT
+#else
+#define AES_128_GCM_KEYSIZE_WSALT SRTP_AES_128_GCM_KEYSIZE_WSALT
+#endif
+
+#if defined(SRTP_AES_GCM_256_KEY_LEN_WSALT)
+#define AES_256_GCM_KEYSIZE_WSALT SRTP_AES_GCM_256_KEY_LEN_WSALT
+#else
+#define AES_256_GCM_KEYSIZE_WSALT SRTP_AES_256_GCM_KEYSIZE_WSALT
+#endif
+
 #define err_status_t srtp_err_status_t
 #define err_status_ok srtp_err_status_ok
 #define err_status_fail srtp_err_status_fail
