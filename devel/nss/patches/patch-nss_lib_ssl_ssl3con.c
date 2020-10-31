$NetBSD: patch-nss_lib_ssl_ssl3con.c,v 1.1 2020/10/31 19:36:30 wiz Exp $

https://hg.mozilla.org/projects/nss/rev/b03a4fc5b902498414b02640dcb2717dfef9682f

--- nss/lib/ssl/ssl3con.c.orig	2020-10-16 14:50:49.000000000 +0000
+++ nss/lib/ssl/ssl3con.c
@@ -6645,11 +6645,7 @@ ssl_CheckServerSessionIdCorrectness(sslS
 
     /* TLS 1.3: We sent a session ID.  The server's should match. */
     if (!IS_DTLS(ss) && (sentRealSid || sentFakeSid)) {
-        if (sidMatch) {
-            ss->ssl3.hs.allowCcs = PR_TRUE;
-            return PR_TRUE;
-        }
-        return PR_FALSE;
+        return sidMatch;
     }
 
     /* TLS 1.3 (no SID)/DTLS 1.3: The server shouldn't send a session ID. */
@@ -8696,7 +8692,6 @@ ssl3_HandleClientHello(sslSocket *ss, PR
                 errCode = PORT_GetError();
                 goto alert_loser;
             }
-            ss->ssl3.hs.allowCcs = PR_TRUE;
         }
 
         /* TLS 1.3 requires that compression include only null. */
@@ -13066,15 +13061,14 @@ ssl3_HandleRecord(sslSocket *ss, SSL3Cip
             ss->ssl3.hs.ws != idle_handshake &&
             cText->buf->len == 1 &&
             cText->buf->buf[0] == change_cipher_spec_choice) {
-            if (ss->ssl3.hs.allowCcs) {
-                /* Ignore the first CCS. */
-                ss->ssl3.hs.allowCcs = PR_FALSE;
+            if (!ss->ssl3.hs.rejectCcs) {
+                /* Allow only the first CCS. */
+                ss->ssl3.hs.rejectCcs = PR_TRUE;
                 return SECSuccess;
+            } else {
+                alert = unexpected_message;
+                PORT_SetError(SSL_ERROR_RX_MALFORMED_CHANGE_CIPHER);
             }
-
-            /* Compatibility mode is not negotiated. */
-            alert = unexpected_message;
-            PORT_SetError(SSL_ERROR_RX_MALFORMED_CHANGE_CIPHER);
         }
 
         if ((IS_DTLS(ss) && !dtls13_AeadLimitReached(spec)) ||
