$NetBSD: patch-xmpp_transports.py,v 1.7 2026/02/08 00:13:38 gdt Exp $

Upstream disables validating certificates.  In 2025, this is a bug.
Record how to address the bug, and why that fails.

https://github.com/xmpppy/xmpppy/issues/71

--- xmpp/transports.py.orig	2026-02-07 23:48:17.000000000 +0000
+++ xmpp/transports.py
@@ -389,6 +389,11 @@ class TLS(PlugIn):
         else:
             protocol = ssl.PROTOCOL_TLS
         context=ssl.SSLContext(protocol)
+        #pkgsrc:
+        #  - Choose defaults for 2025.
+        #  - https://github.com/xmpppy/xmpppy/issues/71
+        #  - \todo hostname is not set, and thus cannot be checked
+        #  - \todo "ssl.SSLCertVerificationError: (SSLCertVerificationError(1, '[SSL: CERTIFICATE_VERIFY_FAILED] certificate verify failed: unable to get local issuer certificate (_ssl.c:1010)'),)"
         context.check_hostname = False
         context.verify_mode = ssl.CERT_NONE
 
