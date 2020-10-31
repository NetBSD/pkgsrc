$NetBSD: patch-nss_lib_ssl_sslimpl.h,v 1.1 2020/10/31 19:36:30 wiz Exp $

https://hg.mozilla.org/projects/nss/rev/b03a4fc5b902498414b02640dcb2717dfef9682f

--- nss/lib/ssl/sslimpl.h.orig	2020-10-16 14:50:49.000000000 +0000
+++ nss/lib/ssl/sslimpl.h
@@ -710,10 +710,7 @@ typedef struct SSL3HandshakeStateStr {
                                            * or received. */
     PRBool receivedCcs;                   /* A server received ChangeCipherSpec
                                            * before the handshake started. */
-    PRBool allowCcs;                      /* A server allows ChangeCipherSpec
-                                           * as the middlebox compatibility mode
-                                           * is explicitly indicarted by
-                                           * legacy_session_id in TLS 1.3 ClientHello. */
+    PRBool rejectCcs;                     /* Excessive ChangeCipherSpecs are rejected. */
     PRBool clientCertRequested;           /* True if CertificateRequest received. */
     PRBool endOfFlight;                   /* Processed a full flight (DTLS 1.3). */
     ssl3KEADef kea_def_mutable;           /* Used to hold the writable kea_def
