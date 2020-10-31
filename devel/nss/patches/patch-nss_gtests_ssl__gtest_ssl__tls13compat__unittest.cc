$NetBSD: patch-nss_gtests_ssl__gtest_ssl__tls13compat__unittest.cc,v 1.1 2020/10/31 19:36:30 wiz Exp $

https://hg.mozilla.org/projects/nss/rev/b03a4fc5b902498414b02640dcb2717dfef9682f

--- nss/gtests/ssl_gtest/ssl_tls13compat_unittest.cc.orig	2020-10-16 14:50:49.000000000 +0000
+++ nss/gtests/ssl_gtest/ssl_tls13compat_unittest.cc
@@ -348,8 +348,8 @@ TEST_F(TlsConnectStreamTls13, ChangeCiph
   client_->CheckErrorCode(SSL_ERROR_HANDSHAKE_UNEXPECTED_ALERT);
 }
 
-// The server rejects a ChangeCipherSpec if the client advertises an
-// empty session ID.
+// The server accepts a ChangeCipherSpec even if the client advertises
+// an empty session ID.
 TEST_F(TlsConnectStreamTls13, ChangeCipherSpecAfterClientHelloEmptySid) {
   EnsureTlsSetup();
   ConfigureVersion(SSL_LIBRARY_VERSION_TLS_1_3);
@@ -358,9 +358,8 @@ TEST_F(TlsConnectStreamTls13, ChangeCiph
   client_->Handshake();  // Send ClientHello
   client_->SendDirect(DataBuffer(kCannedCcs, sizeof(kCannedCcs)));  // Send CCS
 
-  server_->ExpectSendAlert(kTlsAlertUnexpectedMessage);
-  server_->Handshake();  // Consume ClientHello and CCS
-  server_->CheckErrorCode(SSL_ERROR_RX_MALFORMED_CHANGE_CIPHER);
+  Handshake();
+  CheckConnected();
 }
 
 // The server rejects multiple ChangeCipherSpec even if the client
@@ -381,7 +380,7 @@ TEST_F(Tls13CompatTest, ChangeCipherSpec
   server_->CheckErrorCode(SSL_ERROR_RX_MALFORMED_CHANGE_CIPHER);
 }
 
-// The client rejects a ChangeCipherSpec if it advertises an empty
+// The client accepts a ChangeCipherSpec even if it advertises an empty
 // session ID.
 TEST_F(TlsConnectStreamTls13, ChangeCipherSpecAfterServerHelloEmptySid) {
   EnsureTlsSetup();
@@ -398,9 +397,10 @@ TEST_F(TlsConnectStreamTls13, ChangeCiph
                          // send ServerHello..CertificateVerify
   // Send CCS
   server_->SendDirect(DataBuffer(kCannedCcs, sizeof(kCannedCcs)));
-  client_->ExpectSendAlert(kTlsAlertUnexpectedMessage);
-  client_->Handshake();  // Consume ClientHello and CCS
-  client_->CheckErrorCode(SSL_ERROR_RX_MALFORMED_CHANGE_CIPHER);
+
+  // No alert is sent from the client. As Finished is dropped, we
+  // can't use Handshake() and CheckConnected().
+  client_->Handshake();
 }
 
 // The client rejects multiple ChangeCipherSpec in a row even if the
